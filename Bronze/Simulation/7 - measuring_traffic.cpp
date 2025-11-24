#include <climits>
#include <fstream>
#include <vector>

int main()
{
  std::ifstream ifs("traffic.in");
  std::ofstream ofs("traffic.out");

  int n;
  ifs >> n;

  std::vector<std::string> ramps(n);
  std::vector<int> a(n), b(n);

  for (int i = 0; i < n; ++i) {
    ifs >> ramps[i] >> a[i] >> b[i];
  }

  int low = 0, high = 1e9;
  for (int i = n - 1; i >= 0; --i) {
    if (ramps[i] == "none") {
      low = std::max(low, a[i]);
      high = std::min(high, b[i]);
    } else if (ramps[i] == "off") {
      low += a[i];
      high += b[i];
    } else if (ramps[i] == "on") {
      low -= b[i];
      high -= a[i];
      low = std::max(low, 0);
    }
  }

  ofs << low << " " << high << std::endl;

  low = 0, high = 1e9;
  for (int i = 0; i < n; ++i) {
    if (ramps[i] == "none") {
      low = std::max(low, a[i]);
      high = std::min(high, b[i]);
    } else if (ramps[i] == "off") {
      low -= b[i];
      high -= a[i];
      low = std::max(low, 0);
    } else if (ramps[i] == "on") {
      low += a[i];
      high += b[i];
    }
  }

  ofs << low << ' ' << high << std::endl;

  return 0;
}
