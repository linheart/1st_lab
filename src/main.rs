mod is_palindrome;

use is_palindrome::is_palindrome;

fn remove_whitespace(s: &str) -> String {
    return s.chars().filter(|c| !c.is_whitespace()).collect()
}

fn main() {
    let mut a = "refer";
    println!("{}", is_palindrome(&remove_whitespace(&mut a)));
}
