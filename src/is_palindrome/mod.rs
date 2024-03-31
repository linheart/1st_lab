pub fn is_palindrome(input_str: &str) -> bool {
    let reverse_string: String = input_str.chars().rev().collect();
    return input_str == reverse_string;
}
