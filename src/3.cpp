#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // time and space complexity : O(N), O(1)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0, ans = 0;
        char slide_in, slide_out;

        int sz = s.size();
        while (right < sz) {
            // try to slide in s[right]
            slide_in = s[right];
            ++right;
            window[slide_in]++;

            // slide out when repeated character appears
            while (window[slide_in] > 1) {
                slide_out = s[left];
                ++left;
                window[slide_out]--;
            }

            // update answer
            ans = max(ans, right - left);
        }

        return ans;
    }
};

