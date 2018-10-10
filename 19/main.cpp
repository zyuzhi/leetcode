#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto pre_head = new ListNode(0);
    pre_head->next = head;
    auto node = pre_head;
    auto pre = pre_head;
    for (int i = 0; i < n + 1; ++i) {
      node = node->next;
    }
    while (node) {
      node = node->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return pre_head->next;
  }
};

static const auto desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main() {
  auto head = new ListNode(1);
  auto tmp = head;
  for (int i = 2; i <= 2; ++i) {
    tmp->next = new ListNode(i);
    tmp = tmp->next;
  }
  Solution s;
  s.removeNthFromEnd(head, 1);
  return 0;
}