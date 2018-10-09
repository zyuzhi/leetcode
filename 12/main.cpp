#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const int val[] = {
    1000,
    900,
    500,
    400,
    100,
    90,
    50,
    40,
    10,
    9,
    5,
    4,
    1
};

static const string c[] = {
    "M",
    "CM",
    "D",
    "CD",
    "C",
    "XC",
    "L",
    "XL",
    "X",
    "IX",
    "V",
    "IV",
    "I"
};

class Solution {
 public:
  string intToRoman(int num) {
    auto v = num;
    string res;
    for (int i = 0; i < 13; ++i) {
      auto n = v / val[i];
      if (n != 0) {
        for (int j = 0; j < n; ++j) {
          res.append(c[i]);
        }
        v -= n * val[i];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.intToRoman(1994) << endl;
  return 0;
}