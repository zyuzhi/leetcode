#include <iostream>
#include <set>
using namespace std;

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    set<char> s;
    for (const auto& c : J) {
      s.insert(c);
    }
    int count = 0;
    for (const auto& c : S) {
      if (s.find(c) != s.end()) {
        count++;
      }
    }

    return count;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}