fn main() {
    let x: u32 = 0xFFFFFFFF;
    let p: i32 = 31;
    let n: i32 = 32;
    
    let mask = !(!0_u32 << n) << (p - (n - 1));
    let result = x ^ mask;
    
    println!("x: {:032b}", x);
    println!("mask: {:032b}", mask);
    println!("result: {:032b}", result);
}