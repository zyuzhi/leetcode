#include <iostream>

using namespace std;

static const auto desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0) {
            return false;
        } else if (num & (num - 1)) {
            return false;
        }
        return (num & 0x55555555) == num;
    }
};

int main() {
  Solution s;
  cout << s.isPowerOfFour(64) << endl;
  return 0;
}