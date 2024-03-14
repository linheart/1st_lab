mod count_vowels;

use count_vowels::count_vowels;

use std::io;


fn main(){
    let mut input_str = String::new();

    println!("Write text to know how many vowels in it");
    
    match io::stdin().read_line(&mut input_str) {
        Ok(_) => {},
        Err(_) => {println!("Failed to read a string")}
    }

    println!("There is {} vowels in your text", count_vowels(&input_str));
}
