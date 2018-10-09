#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    set<string> s;
    for (const auto &w : words) {
      string t;
      for (char c : w) {
        const auto &str = _vec[c - 'a'];
        t += str;
      }
      if (s.find(t) == s.end()) {
        s.insert(std::move(t));
      }
    }
    return s.size();
  }
 private:
  const static vector<string> _vec;
};

const vector<string> Solution::_vec = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
};

int main() {
  vector<string> v = {
      "uirqyr","ffqkc","joq","joq","joq"
  };
  Solution s;
  s.uniqueMorseRepresentations(v);
  return 0;
}