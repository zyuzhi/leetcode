#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const auto desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  vector<int> countBits(int num) {
    if (num == 0) {
      return {0};
    }
    const auto count = num + 1;
    vector<int> v(count);
    v[0] = 0;
    v[1] = 1;
    auto n = 2;
    auto i = 2;
    while (true) {
      bool is_break = false;
      for (int j = 0; j < n; ++j, ++i) {
        if (i >= count) {
          is_break = true;
          break;
        }
        v[i] = v[j] + 1;
      }
      if (is_break) {
        break;
      }
      n <<= 1;
    }
    return v;
  }
};

int main() {
  Solution s;
  s.countBits(5);
  return 0;
}