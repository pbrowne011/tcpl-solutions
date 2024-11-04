fn invert(x: u32, p: i32, n: i32) -> u32 {
    let mask = !(!0_u32 << n) << (p - (n - 1));
    x ^ mask
}

fn main() {
    let result = invert(0xFFFFFFFF, 31, 32);
    println!("result: {:032b}", result);
}