cmake_minimum_required(VERSION 3.8)
project(ros2_cargo_in_cmake)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
add_subdirectory(src_rust)

add_executable(ros2_cargo_in_cmake src/main.cpp)
target_link_libraries(ros2_cargo_in_cmake src_rust)
target_include_directories(ros2_cargo_in_cmake PRIVATE include)
ament_target_dependencies(ros2_cargo_in_cmake rclcpp)

install(
  TARGETS ros2_cargo_in_cmake
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
