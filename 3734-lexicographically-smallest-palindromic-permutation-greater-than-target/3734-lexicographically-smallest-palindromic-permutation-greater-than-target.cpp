class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int halfLen = n / 2;

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Count characters available for left half
        vector<int> halfCnt(26, 0);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        string targetHalf = target.substr(0, halfLen);

        // --------------------------------------------------
        // CASE 1:
        // Can targetHalf itself be used as the left half?
        // If yes, construct that palindrome and check it.
        // --------------------------------------------------

        vector<int> temp = halfCnt;
        bool possible = true;

        for (char c : targetHalf) {

            int x = c - 'a';

            if (temp[x] == 0) {
                possible = false;
                break;
            }

            temp[x]--;
        }

        if (possible) {

            string candidate = targetHalf;

            if (n % 2) {
                candidate += middle;
            }

            candidate += string(targetHalf.rbegin(),
                                targetHalf.rend());

            // Important!
            // The left half can be equal to target's left half,
            // but the COMPLETE palindrome can still be greater.
            if (candidate > target) {
                return candidate;
            }
        }

        // --------------------------------------------------
        // CASE 2:
        // Find the smallest left half greater than targetHalf
        // --------------------------------------------------

        for (int pivot = halfLen - 1; pivot >= 0; pivot--) {

            vector<int> remaining = halfCnt;

            // Match targetHalf before pivot
            bool prefixPossible = true;

            for (int i = 0; i < pivot; i++) {

                int x = targetHalf[i] - 'a';

                if (remaining[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                remaining[x]--;
            }

            if (!prefixPossible) {
                continue;
            }

            // At pivot, choose the smallest character
            // strictly greater than targetHalf[pivot]
            int targetChar = targetHalf[pivot] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {

                if (remaining[c] == 0) {
                    continue;
                }

                string left = targetHalf.substr(0, pivot);

                left += char('a' + c);

                remaining[c]--;

                // Fill remaining positions with smallest chars
                for (int x = 0; x < 26; x++) {

                    while (remaining[x] > 0) {
                        left += char('a' + x);
                        remaining[x]--;
                    }
                }

                // Construct palindrome
                string candidate = left;

                if (n % 2) {
                    candidate += middle;
                }

                candidate += string(left.rbegin(),
                                    left.rend());

                return candidate;
            }
        }

        return "";
    }
};