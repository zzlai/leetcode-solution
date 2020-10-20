#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

#if 0
class Solution {
public:
    // brute force
    // time and space complexity : O(N^2), O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};
#endif

#if 0
class Solution {
public:
    // hash
    // time and space complexity : O(N), O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        unordered_map<int, int> dict;   // <nums[i], i>
        for (int i = 0; i < sz; ++i) {
            dict.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < sz; ++i) {
            auto iter = dict.find(target - nums[i]);
            if (iter != dict.end() && iter->second != i)
                return vector<int>{i, iter->second};
        }

        return vector<int>{-1, -1};
    }
};
#endif

class Solution {
public:
    // hash
    // time and space complexity : O(N), O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        unordered_map<int, int> dict;   // <nums[i], i>

        for (int i = 0; i < sz; ++i) {
            auto iter = dict.find(target - nums[i]);
            if (iter != dict.end() && iter->second != i)
                return vector<int>{iter->second, i};
            dict.insert(make_pair(nums[i], i));
        }

        return vector<int>{-1, -1};
    }
};


