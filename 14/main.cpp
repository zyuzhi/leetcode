#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    } else if (strs.size() == 1) {
      return strs[0];
    }
    string res;
    int pos = 0;
    while (true) {
      char c = strs[0][pos];
      bool is_same = true;
      for (int i = 1; i < strs.size(); ++i) {
        if (pos >= strs[i].length()) {
          is_same = false;
          break;
        } else if (c == strs[i][pos]) {
          // pass
        } else {
          is_same = false;
          break;
        }
      }
      if (is_same) {
        res += c;
      } else {
        break;
      }
      pos++;
    }
    return res;
  }
};

int main() {
  vector<string> v = {
      "dog","racecar","car"
  };
  Solution s;
  cout << s.longestCommonPrefix(v) << endl;
  return 0;
}