char* clearDigits(char* s) {
    int n = strlen(s), k = 0;
    char *res = (char *)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            k--;
        } else {
            res[k++] = s[i];
        }
    }
    res[k] = '\0';
    return res;
}
