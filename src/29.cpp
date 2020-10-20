#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long lldividend = dividend;
        long long lldivisor = divisor;

        bool negative = false;
        if (lldividend > 0 && lldivisor > 0) {
            negative = false;
        }
        else if (lldividend < 0 && lldivisor < 0) {
            negative = false;
            lldividend = -lldividend;
            lldivisor = -lldivisor;
        }
        else {
            negative = true;
            if (lldividend < 0) lldividend = -lldividend;
            if (lldivisor < 0) lldivisor = -lldivisor;
        }

        long long ans = 0;
        while (lldividend >= lldivisor) {
            ++ans;
            lldividend -= lldivisor;
        }

        if (negative) ans = -ans;
        return (ans >= INT_MIN && ans <= INT_MAX) ? ans : INT_MAX;
    }
};

int main() {
    Solution s;

    cout << s.divide(1, 1) << endl;

    return 0;
}