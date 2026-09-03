class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = 0;
        int result = INT_MAX;
        int sum = 0;
        int n = nums.size();
        while(high < n){
            sum = sum + nums[high];
            while(sum >= target){
                int len = high - low + 1;
                result = min(len,result);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }

        if (result == INT_MAX){
            return 0;
        }
        return result;
    }
};