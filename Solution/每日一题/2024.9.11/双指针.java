class Solution {
    public int maximizeWin(int[] prizePositions, int k) {
        int ans = 0;
        for (int l1 = 0, r1 = 0, l2 = 0, r2 = 0, firstMax = 0; r2 < prizePositions.length; r2++) {
            while (prizePositions[r2] - prizePositions[l2] > k) {
                l2++;
            }
            for (; r1 < l2; r1++) {
                while (prizePositions[r1] - prizePositions[l1] > k) {
                    l1++;
                }
                firstMax = Math.max(firstMax, r1 - l1 + 1);
            }
            ans = Math.max(ans, r2 - l2 + 1 + firstMax);
        }
        return ans;
    }
}
