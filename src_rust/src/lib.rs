#[no_mangle]
pub extern "C" fn fibonacci_sequence(array: *mut usize, length: usize) {
    let array = unsafe { std::slice::from_raw_parts_mut(array, length) };
    for i in 0..length {
        array[i] = fibonacci(i);
    }
}

fn fibonacci(n: usize) -> usize {
    match n {
        0 => 0,
        1 => 1,
        _ => fibonacci(n - 1) + fibonacci(n - 2),
    }
}
