class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int Sum = 0;
        int res = 0;
        int n = nums.size();
        unordered_map <int,int> f;
        f[0]=1;
        for(int i = 0; i<n;i++){
            Sum+=nums[i];
            int rem = Sum % k;
            if (rem < 0){
                rem = rem + k;
            }
            res+=f[rem];
            f[rem]++;
        }
        return res;
    }
};