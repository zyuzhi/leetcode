#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    queue<int> s;
    bool is_minus = x < 0;
    int v = x;
    while (v) {
      s.push(std::abs(v % 10));
      v /= 10;
    }
    int res = 0;
    while (!s.empty()) {
      res = res * 10 + s.front();
      s.pop();
    }
    if (is_minus) {
      res = -res;
    }
    if (check(x, res)) {
      return res;
    } else {
      return 0;
    }
  }

  bool check(int ori, int rev) {
    if (!((ori >= 0) ^ (rev < 0))) {
      return false;
    }
    vector<int> ori_vec;
    vector<int> rev_vec;

    int v = ori;
    while (v) {
      int c = std::abs(v % 10);
      if (ori_vec.size() == 0 && c == 0) {
      } else {
        ori_vec.push_back(c);
      }
      v /= 10;
    }

    v = rev;
    while (v) {
      rev_vec.insert(rev_vec.begin(), std::abs(v % 10));
      v /= 10;
    }
    if (rev_vec.size() != ori_vec.size()) {
      return false;
    }
    return rev_vec == ori_vec;
  }
};
int main() {
  Solution s;
  // std::cout << s.reverse(-123) << std::endl;
  std::cout << s.reverse(101020) << std::endl;
  return 0;
}