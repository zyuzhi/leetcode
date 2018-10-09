#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const auto desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  int maxArea(vector<int>& height) {
    auto n = height.size();
    auto max_res = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto res = std::min(height[i], height[j]) * (j - i);
        if (res > max_res) {
          swap(res, max_res);
        }
      }
    }
    return max_res;
  }
};
int main() {
  vector<int> v = {
      1,8,6,2,5,4,8,3,7
  };
  Solution s;
  cout << s.maxArea(v) << endl;
  return 0;
}