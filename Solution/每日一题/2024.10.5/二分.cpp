# 这种需要查找的东西，一般都可以利用二分，见了好多这种题了
class Solution {  

  
public:  

  
    long long minimumTime(vector<int>& time,int totalTrips) {  
        long long l = 1, r = 1e16;
        while (l < r) { // 修改循环条件，确保在找到解时退出  

        
        auto check = [&](long long limit) {
            long long cnt = 0;
            for(int t: time) {
                cnt += limit / t;
                if(cnt >= totalTrips) return true;
            }
            return false;
        };
            long long mid = (l + r) / 2;  
            if (check(mid)) { // 传递 time 数组给 check 函数  
                r = mid;  
            } else {  
                l = mid + 1;  
            }  
        }  
        return l;  
    }  
};  
