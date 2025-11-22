#include <algorithm>
#include <fstream>
#include <vector>

int main()
{
  std::ifstream ifs("blist.in");
  std::ofstream ofs("blist.out");

  std::vector<int> times(1000, 0);

  int n;
  ifs >> n;

  for (int i = 0; i < n; ++i) {
    int s, t, b;
    ifs >> s >> t >> b;
    for (int j = s; j <= t; ++j) {
      times[j] += b;
    }
  }

  ofs << *std::max_element(times.begin(), times.end());

  return 0;
}
