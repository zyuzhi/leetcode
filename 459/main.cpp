#include <iostream>
#include <string>

using namespace std;

static const auto desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    for (int i = 1; i <= s.length() / 2; ++i) {
      if (s.length() % i != 0) {
        continue;
      }
      auto n = s.length() / i;
      auto t = s.substr(0, i);
      bool is_same = true;
      for (int j = 1; j < n; ++j) {
        if (t != s.substr(i * j, i)) {
          is_same = false;
          break;
        }
      }
      if (is_same) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.repeatedSubstringPattern("b") << endl;
  return 0;
}