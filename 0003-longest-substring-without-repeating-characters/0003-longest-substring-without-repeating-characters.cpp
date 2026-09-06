class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0 ;
        int res = 0;
        unordered_map<char,int> str;
        int n = s.size();
        for(int high = 0; high<n ; high++){
            str[s[high]]++;
            while(str[s[high]] > 1){
                str[s[low]]--;
                low++;
            }
            int len = high - low + 1;
            res = max(res,len);
        }
        return res;
    }
};