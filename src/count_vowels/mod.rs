mod consts;

use consts::VOWELS;

pub fn count_vowels(input_str: &str) -> i32{
    let mut count = 0;
    for character in input_str.chars() {
        if VOWELS.contains(&character){
            count += 1;
        }
    }
    return count;
}
