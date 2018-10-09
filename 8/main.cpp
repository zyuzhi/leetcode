#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int i = 0;
    for (; i < str.length(); ++i) {
      const auto c = str[i];
      if (c == ' ') {
        continue;
      } else if (!std::isdigit(c) && c != '-' && c != '+') {
        return 0;
      } else if (std::isdigit(c) || c == '-' || c == '+') {
        break;
      }
    }
    bool is_minus = str[i] == '-';
    if (str[i] == '-' || str[i] == '+') {
      ++i;
    }
    for (; i < str.length(); ++i) {
      if (str[i] == ' ') {
        return 0;
      }
      break;
    }
    int res = 0;
    for (; i < str.length(); ++i) {
      if (!std::isdigit(str[i])) {
        break;
      }
      int c = str[i] - '0';
      if (!is_minus) {
        int temp = (INT32_MAX - c) / 10;
        if (temp < res) {
          return INT32_MAX;
        } else if (temp == res) {
          if (c > INT32_MAX % 10) {
            return INT32_MAX;
          }
        }
      } else if (is_minus) {
        int temp = (INT32_MAX - c) / 10;
        if (temp < res) {
          return INT32_MIN;
        } else if (temp == res) {
          if (c - 1 > INT32_MAX % 10) {
            return INT32_MIN;
          }
        }
      }
      res = res * 10 + c;
    }
    if (is_minus) {
      return -res;
    }
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.myAtoi("-000000000000001") << std::endl;
  return 0;
}