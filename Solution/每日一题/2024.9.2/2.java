class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        char[] s = answerKey.toCharArray();
        int ans = 0;
        int left = 0;
        int[] cnt = new int[2];
        for (int right = 0; right < s.length; right++) {
            cnt[s[right] >> 1 & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[left++] >> 1 & 1]--;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}
