class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0 ; 
        int n = height.size();
        int i = 0;   //Leftpointer
        int j = n-1; //Rightpointer
        while(i<j){
            int width = j - i;
            int ht = min(height[i],height[j]);
            int area = width * ht;
            maxwater = max(maxwater,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};