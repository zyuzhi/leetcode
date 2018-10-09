#include <iostream>

using namespace std;

class Solution {
 public:
  string toLowerCase(string str) {
    string res;
    for (auto c : str) {
      if (c >= 'A' && c <= 'Z') {
        c = (c - 'A') + 'a';
      }
      res += c;
    }
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.toLowerCase("asdfAS") << std::endl;
  return 0;
}