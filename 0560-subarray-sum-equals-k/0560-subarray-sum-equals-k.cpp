class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Sum = 0;
        unordered_map <int,int> f;
        f[0] = 1;
        int n = nums.size();
        int res=0;
        for(int i = 0;i<n;i++){
            Sum+=nums[i];
            int q = Sum-k;
            int freq = f[q];
            res += freq;
            f[Sum]++;
        }
        return res;
    }
};