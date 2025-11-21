#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
  std::ifstream ifs("cowqueue.in");
  std::ofstream ofs("cowqueue.out");

  int n;
  ifs >> n;

  std::vector<std::pair<int, int>> cows(n);
  for (auto& pair : cows) {
    ifs >> pair.first >> pair.second;
  }

  std::sort(cows.begin(), cows.end());

  int time = 0;
  for (const auto& pair : cows) {
    if (pair.first >= time) {
      time = pair.first + pair.second;
    } else {
      time += pair.second;
    }
  }

  ofs << time;

  return 0;
}
