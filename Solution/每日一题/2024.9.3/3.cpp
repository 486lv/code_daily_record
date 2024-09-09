class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long mn = nums[0], mx = mn;
        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long tmp = mn;
            mn = min({mn, x, mn * x, mx * x});
            mx = max({mx, x, tmp * x, mx * x});
        }
        return mx;
    }
};

