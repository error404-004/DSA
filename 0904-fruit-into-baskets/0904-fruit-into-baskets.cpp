class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0 , high = 0;
        int res = INT_MIN;
        int n = fruits.size();

        unordered_map<int,int> basket;
        for(high = 0 ; high<n ; high++){
            basket[fruits[high]]++;
            
            while(basket.size() > 2){
                basket[fruits[low]]--;
                if(basket[fruits[low]]==0){
                    basket.erase(fruits[low]);
                }
                low++;
            }
            int len = high - low + 1;
            res = max(len,res);
        }
        return res;
    }
};