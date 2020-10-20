#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        // 转置
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 逆序
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};

