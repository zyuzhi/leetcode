#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  inline int c_to_v(char c) {
    switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      default:
        return 1000;
    }
  }
  int romanToInt(string s) {
    const auto l = s.length();
    int res = c_to_v(s[0]);
    int last = res;
    for (int i = 1; i < l; ++i) {
      auto current_val = c_to_v(s[i]);
      res += current_val;
      if (current_val > last) {
        res -= last * 2;
      }
      last = current_val;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.romanToInt("MCMXCIV") << endl;
  return 0;
}