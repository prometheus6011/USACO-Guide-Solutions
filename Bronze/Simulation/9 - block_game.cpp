#include <fstream>
#include <vector>
#include <string>

int main()
{
  std::ifstream ifs("blocks.in");
  std::ofstream ofs("blocks.out");

  int n;
  ifs >> n;

  std::vector<int> freq(26, 0);
  for (int i = 0; i < n; ++i) {
    std::string s1, s2;
    ifs >> s1 >> s2;
    std::vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1) {
      ++freq1[c - 'a'];
    }

    for (char c : s2) {
      ++freq2[c - 'a'];
    }

    for (int j = 0; j < 26; ++j) {
      freq[j] += std::max(freq1[j], freq2[j]);
    }
  }

  for (int i : freq) ofs << i << '\n';

  return 0;
}
