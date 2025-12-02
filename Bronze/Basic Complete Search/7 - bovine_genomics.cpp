#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <iostream>

int main()
{
  std::ifstream ifs("cownomics.in");
  std::ofstream ofs("cownomics.out");

  int n, m;
  ifs >> n >> m;
  std::vector<std::string> spotty(n);
  std::vector<std::string> plain(n);
  for (int i = 0; i < n; ++i) {
    ifs >> spotty[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> plain[i];
  }

  int res = 0;
  for (int i = 0; i < m; ++i) {
    std::set<char> spotty_st;
    for (int j = 0; j < n; ++j) {
      spotty_st.insert(spotty[j][i]);
    }

    std::set<char> plain_st;
    for (int j = 0; j < n; ++j) {
      plain_st.insert(plain[j][i]);
    }

    bool is_disjoint = true;
    for (const auto& s : spotty_st) {
      if (!is_disjoint) break;
      is_disjoint = (plain_st.find(s) == plain_st.end());
    }
    for (const auto& s : plain_st) {
      if (!is_disjoint) break;
      is_disjoint = (spotty_st.find(s) == spotty_st.end());
    }
    if (is_disjoint) ++res;
  }

  ofs << res;

  return 0;
}
