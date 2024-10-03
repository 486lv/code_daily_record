


class Solution {
public:
    static constexpr int INFTY = INT_MAX / 2;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<int>> f(maxTime + 1, vector<int>(n, INFTY));
        f[0][0] = passingFees[0];
        for(int t=1;t<=maxTime;t++){
            for(const auto& edge:edges){
                int i=edge[0],j=edge[1],time=edge[2];
                if(time<=t){
                f[t][i]=min(f[t][i],f[t-time][j]+passingFees[i]);
                f[t][j]=min(f[t][j],f[t-time][i]+passingFees[j]);
                }
            }
        }
        int res=INFTY;
        for(int i=1;i<=maxTime;i++){
            res=min(res,f[i][n-1]);

        }
        if(res==INFTY) return -1;
        else return res;
    }
};
