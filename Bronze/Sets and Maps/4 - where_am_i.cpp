#include <fstream>
#include <set>
#include <string>

int main()
{
  std::ifstream ifs("whereami.in");
  std::ofstream ofs("whereami.out");

  int n;
  ifs >> n;
  std::string s;
  ifs >> s;

  for (int k = 1; k <= n; ++k) {
    std::set<std::string> seen;
    bool found = true;

    for (int i = 0; i + k <= n; ++i) {
      std::string sub = s.substr(i, k);
      if (seen.find(sub) != seen.end()) {
        found = false;
        break;
      }
      seen.insert(sub);
    }

    if (found) {
      ofs << k;
      return 0;
    }
  }

  return 0;
}
