#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> lines;
    vector<string> line_vec;
    int line_width = 0;
    int word_count = 0;
    const auto l = words.size();
    const auto l_1 = l - 1;
    for (int i = 0; i < l; ++i) {
      const auto &word = words[i];
      if (line_width + word.length() > maxWidth) {
        const auto v_l = line_vec.size();
        const auto v_l_1 = v_l - 1;
        string line;
        // line
        if (v_l_1 != 0) {
          auto w_c = (maxWidth - word_count) / v_l_1;
          auto w_c_left = (maxWidth - word_count) % v_l_1;
          vector<int> space_count(v_l_1, w_c);
          for (int j = 0; j < w_c_left; ++j) {
            space_count[j]++;
          }
          for (int j = 0; j < v_l_1; ++j) {
            line.append(line_vec[j]);
            for (int n = 0; n < space_count[j]; ++n) {
              line += ' ';
            }
          }
          line.append(line_vec[v_l_1]);
        } else {
          line.append(line_vec[0]);
          for (int j = 0; j < maxWidth - word_count; ++j) {
            line += ' ';
          }
        }
        lines.push_back(move(line));
        line_vec.clear();
        line_width = 0;
        word_count = 0;
      }
      if (i == l_1) {
        line_vec.push_back(word);
        line_width += word.length();
        word_count += word.length();
        const auto v_l = line_vec.size();
        const auto v_l_1 = v_l - 1;
        string line;
        // last line
        auto last_space_count = maxWidth - line_width;
        for (int j = 0; j < v_l_1; ++j) {
          line.append(line_vec[j]);
          line += ' ';
        }
        line.append(line_vec[v_l_1]);
        for (int j = 0; j < last_space_count; ++j) {
          line += ' ';
        }
        lines.push_back(move(line));
      }
      line_vec.push_back(word);
      line_width += word.length() + 1;
      word_count += word.length();
    }
    return lines;
  }
};

int main() {
  vector<string> words = {
      //"What","must","be","acknowledgment","shall","be","acknowledgment",
      "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"
      //"What","must","be","acknowledgment","shall","be"
  };
  Solution s;
  auto res = s.fullJustify(words, 20);
  for (auto &line : res) {
    cout << line << endl;
  }
  return 0;
}