#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

#if 0
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9], cols[9], blocks[9];
        int num, block_id;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('1' <= board[i][j] && board[i][j] <= '9') {
                    num = int(board[i][j] - '0');
                    block_id = (i / 3) * 3 + (j / 3);
                    if (rows[i].find(num) != rows[i].end() || cols[j].find(num) != cols[j].end() || 
                        blocks[block_id].find(num) != blocks[block_id].end()) {
                        return false;
                    }
                    else {
                        rows[i].insert(num);
                        cols[j].insert(num);
                        blocks[block_id].insert(num);
                    }
                }
            }
        }

        return true;
    }
};
#endif

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, blocks[9][9] = {0};
        int num, block_id;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('1' <= board[i][j] && board[i][j] <= '9') {
                    num = int(board[i][j] - '0');
                    block_id = (i / 3) * 3 + (j / 3);
                    if (rows[i][num - 1] != 0 || cols[j][num - 1] != 0 || blocks[block_id][num - 1] != 0) {
                        return false;
                    }
                    else {
                        rows[i][num - 1] = 1;
                        cols[j][num - 1] = 1;
                        blocks[block_id][num - 1] = 1;
                    }
                }
            }
        }

        return true;
    }
};


