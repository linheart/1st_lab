mod count_vowels;
//mod is_palindrome;
//mod ?;

use count_vowels::count_vowels;
//use is_palindrome::is_palindrome;
//use ?::?;

use std::io;

use colored::*;


fn main(){
    println!("{}", "========A program for performing an operation on a string========".blue());
    
    loop{
        let mut input_str = String::new();
        let mut operation = String::new();
        println!("Choose the option:\n1 - check if string is palindrom\n2 - count vowels in string\n3 - ?{}", "\nUse Ctrl + C to stop".bright_blue());

        match io::stdin().read_line(&mut operation) {
        Ok(_) => {println!("{}", "Succesful reading".green())},
        Err(_) => {println!("{}", "Failed to read a string".red()); continue}
    }

    match operation.trim().len() {
        1 => {},
        _ => {println!("{}", "invalid option".red()); continue}
    }

    println!("{}", "Enter the line for the operation");
    
    match io::stdin().read_line(&mut input_str) {
        Ok(_) => {println!("{}", "Succesful reading".green())},
        Err(_) => {println!("{}", "Failed to read a string".red()); continue}
    }

    match operation.as_str().trim() {
        // "1" => println!("Your string is palindrome: {}", is_palindrome(&input_str)),
        "2" => println!("{}", format!("There are {} vowels in your text\n", count_vowels(&input_str)).purple()),
        // "3" => println!("{}", ?(&input_str)),
        _ => println!("{}", "Invalid option".red()),
    }
}
}
