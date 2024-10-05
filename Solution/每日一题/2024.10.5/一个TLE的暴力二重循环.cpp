class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int cnt=1;
        while(1){
            long long total=0;
            for(int i=0;i<time.size();i++){
                total+=cnt/time[i];
            }
            if(total>=totalTrips) break;
            cnt++;
        }
        return cnt;
    }
};
