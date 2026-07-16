class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid = 0;
        int Lower = 0;
        int High = n-1;
        
        while (mid<=High){
            if (nums[mid]==0){
                swap(nums[Lower],nums[mid]);
                Lower++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[High],nums[mid]);
                High--;
            }
        }

        return ;
    }
};