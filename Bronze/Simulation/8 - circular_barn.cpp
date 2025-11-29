#include <climits>
#include <fstream>
#include <vector>

int main()
{
  std::ifstream ifs("cbarn.in");
  std::ofstream ofs("cbarn.out");

  int n;
  ifs >> n;
  std::vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    ifs >> r[i];
  }

  long long max_res = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    long long curr_res = 0;
    for (int j = 0; j < n; ++j) {
      int room = (i + j) % n;
      curr_res += 1LL * j * r[room];
    }
    max_res = std::min(max_res, curr_res);
  }

  ofs << max_res;

  return 0;
}
