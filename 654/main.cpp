#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    auto root = new TreeNode(0);
    auto left = nums.begin();
    auto right = nums.end();
    queue<tuple<decltype(left), decltype(right), TreeNode*> > q;
    q.push(make_tuple(left, right, root));
    while (!q.empty()) {
      auto &t = q.front();
      {
        auto &l = get<0>(t);
        auto &r = get<1>(t);
        auto &n = get<2>(t);

        auto max_it = std::max_element(l, r);
        n->val = *max_it;
        if (l < max_it) {
          n->left = new TreeNode(0);
          q.push(make_tuple(l, max_it, n->left));
        }
        if (max_it + 1 < r) {
          n->right = new TreeNode(0);
          q.push(make_tuple(max_it + 1, r, n->right));
        }
      }
      q.pop();
    }
    return root;
  }
};
int main() {
  vector<int> v = {
      3,2,1,6,0,5
  };
  Solution s;
  s.constructMaximumBinaryTree(v);
  return 0;
}