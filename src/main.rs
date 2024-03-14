mod count_vowels;

use count_vowels::count_vowels;

use std::io::{self, Read};


fn main(){
    let mut input_str = String::new();
    let mut limited_stdin = io::stdin().lock().take(255);

    println!("Write text to know how many vowels in it (max is 255 bytes)");
    
    match limited_stdin.read_to_string(&mut input_str) {
        Ok(_) => {},
        Err(_) => {println!("Failed to read a string")}
    }

    println!("There is {} vowels in your text", count_vowels(&input_str));
}
