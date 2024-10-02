
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(ceil(hour)<n) return -1;
        int l=0,r=1e7;
        //其实当时我的想法是在0~1e7里面range遍历，看哪个合适，这么明显居然没有想到用二分查找，糊涂
        auto check = [&](int speed) {
            if(speed==0) return false;
            double totalHours = 0.0;
            for (int i = 0; i < n - 1; i++) {
                totalHours+=ceil(double(dist[i])/double(speed));
                // 这里卡了我好久，原因是直接写了dist/speed，（3/2）其实直接是1了，取ceil就是自我安慰，笑死
                //所以要先转换
            }
            totalHours+=double(dist[n-1])/double(speed);

            if(totalHours>hour) return false;
            else return true;
        };
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)){

                r=mid;
            }
            else{
                l=mid+1;
            }

        }
        return r;
    }
};

