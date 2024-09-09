class Solution {
    public long maxStrength(int[] nums) {
        long max_num=nums[0];
        long min_num=nums[0];
        for(int i=1;i<nums.length;i++){
            int x=nums[i];
            long temp=max_num;
            max_num=Math.max(Math.max(max_num,x),Math.max(max_num*x,min_num*x));
            min_num=Math.min(Math.min(min_num,x),Math.min(temp*x,min_num*x));
        }
        return max_num;
    }
}
