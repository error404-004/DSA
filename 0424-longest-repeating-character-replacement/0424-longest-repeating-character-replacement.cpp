class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0, high = 0;
        int res = 0;
        unordered_map<char, int> f;
        int n =s.size();
        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int maxint = 0;
            for (auto& p : f) {
                maxint = max(maxint, p.second);
            }
            int len = high - low + 1;
            int differ = len - maxint;
            while(differ > k) {
                f[s[low]]--;
                low++;
                maxint = 0;
                for (auto& p : f) {
                    maxint = max(maxint, p.second);
                }
                len = high - low + 1;
                differ = len - maxint;
            }
            len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};
