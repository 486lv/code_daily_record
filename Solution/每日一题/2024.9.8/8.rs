impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut res: Vec<char> = Vec::new();
        for c in s.chars() {
            if c.is_digit(10) {
                res.pop();
            } else {
                res.push(c);
            }
        }
        res.into_iter().collect()
    }
}

