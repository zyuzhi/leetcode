#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    auto rows = grid.size();
    auto cols = grid[0].size();
    vector<int> row_vec(rows, 0);
    vector<int> col_vec(cols, 0);

    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        col_vec[col] = std::max(col_vec[col], grid[row][col]);
        row_vec[row] = std::max(row_vec[row], grid[row][col]);
      }
    }
    int count = 0;
    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        int max_val = std::min(row_vec[row], col_vec[col]);
        count += max_val - grid[row][col];
      }
    }
    return count;
  }
};

int main() {
  vector<vector<int>> g = {
      {3, 0, 8, 4},
      {2, 4, 5, 7},
      {9, 2, 6, 3},
      {0, 3, 1, 0},
  };
  Solution s;
  s.maxIncreaseKeepingSkyline(g);
  return 0;
}