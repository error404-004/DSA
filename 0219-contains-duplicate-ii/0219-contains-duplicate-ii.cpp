class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        int n = nums.size();
        unordered_map<int,int> mp;
        
        for(int high = 0; high < n; high++){
            if(mp.find(nums[high]) != mp.end()){
                if(high - mp[nums[high]] <= k){
                    return true;
                }
            }

        mp[nums[high]] = high;
        }
        return false;
    }
};