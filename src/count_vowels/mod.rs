pub fn count_vowels(input_str: &str) -> usize {
    let count;
    count = input_str
        .chars()
        .filter(|&c| "aeiouyAEIOUY".contains(c))
        .count();
    return count;
}
