#include <cstddef>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include "ros2_cargo_in_cmake/src_rust.hpp"

class CargoInCMakeNode : public rclcpp::Node {
public:
  CargoInCMakeNode() : rclcpp::Node("cargo_in_cmake_node") {
    timer_ = this->create_wall_timer(std::chrono::seconds{1}, [this] {
      std::vector<size_t> vec(10);
      fibonacci_sequence(vec.data(), vec.size()); // Rust側関数の呼び出し
      for (size_t i = 0; i < vec.size(); ++i) {
        RCLCPP_INFO(this->get_logger(), "fibonacci(%ld) = %ld", i, vec[i]);
      }
    });
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CargoInCMakeNode>());
  rclcpp::shutdown();
  return 0;
}
