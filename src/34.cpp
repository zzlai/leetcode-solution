#include <vector>
#include <iostream>
using namespace std;

#if 0
class Solution {
public:
    // 枚举
    // 时间和空间复杂度：O(N), O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        int lbound = -1, rbound = -1;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == target) {
                if (lbound == -1) lbound = i;
                else rbound = i;
            }
        }

        if (lbound != -1) return {lbound, rbound != -1 ? rbound : lbound};
        else return {lbound, rbound};
    }
};

#endif

#if 0
class Solution {
public:
    // 二分搜索
    // 时间和空间复杂度：O(logN), O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int lbound = bound(nums, target, "left");
        int rbound = bound(nums, target, "right");
        return {lbound, rbound};
    }

    int bound(vector<int>& nums, int target, string bound_type) {
        int sz = nums.size();
        int mid, l =0, r = sz - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                // 如果求左边界则调整右指针往左边界逼近；如果求右边界则调整左指针往右边界逼近
                if (bound_type == "left") r = mid - 1;
                else if (bound_type == "right") l = mid + 1;
            }
            else if (nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;
        }

        if (bound_type == "left") {
            if (l >= sz || nums[l] != target) return -1;
            return l;
        }
        else if (bound_type == "right") {
            if (r < 0 || nums[r] != target) return -1;
            return r;
        }

        return -1;
    }

    /*
    // 返回左边界下标
    int left_bound(vector<int>& nums, int target) {
	    int mid, l = 0, r = nums.size() - 1;
	    while (l <= r) {
		    mid = l + (r - l) / 2;
		    if (nums[mid] == target) r = mid - 1;
		    else if (nums[mid] < target) l = mid + 1;
		    else if (nums[mid] > target) r = mid - 1;
	    }

	    if (l > nums.size() || nums[l] != target) return -1;
	    return l;
    }

    // 返回右边界下标
    int right_bound(vector<int>& nums, int target) {
	    int mid, l = 0, r = nums.size() - 1;
	    while (l <= r) {
		    mid = l + (r - l) / 2;
		    if (nums[mid] == target) l = mid + 1;
		    else if (nums[mid] < target) l = mid + 1;
		    else if (nums[mid] > target) r = mid - 1;
	    }
	    if (r < 0 || nums[r] != target) return -1;
	    return r;
    }
    */
};
#endif

#if 0
int main() {
    vector<int> nums = {2, 2};

    Solution s;
    vector<int> ret = s.searchRange(nums, 3);
    return 0;
}
#endif
