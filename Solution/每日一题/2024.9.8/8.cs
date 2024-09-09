public class Solution {
    public string ClearDigits(string s) {
        StringBuilder res = new StringBuilder();
        foreach (char c in s.ToCharArray()) {
            if (Char.IsDigit(c)) {
                res.Remove(res.Length - 1, 1);
            } else {
                res.Append(c);
            }
        }
        return res.ToString();
    }
}

