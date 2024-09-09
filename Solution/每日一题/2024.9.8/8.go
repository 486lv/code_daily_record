func clearDigits(s string) string {
    var res []byte
    for _, c := range s {
        if unicode.IsDigit(c) {
            res = res[:len(res)-1]
        } else {
            res = append(res, byte(c))
        }
    }
    return string(res)
}

