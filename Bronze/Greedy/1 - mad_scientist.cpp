#include <fstream>
#include <string>
#include <iostream>

int main(void)
{
  std::ifstream ifs("breedflip.in");
  std::ofstream ofs("breedflip.out");

  int n;
  ifs >> n;
  std::string a, b;
  ifs >> a >> b;

  int res = 0;

  int left = 0;
  for (int right = 0; right < n; ++right) {
    if (a[right] != b[right]) continue;
    std::cout << left << "\t" << right << std::endl;
    bool transform = false;
    while (left <= right) {
      if (a[left] == b[left]) {
        ++left;
        continue;
      }
      transform = true;
      a[left] = (a[left] == 'G' ? 'H' : 'G');
      ++left;
    }
    if (transform) ++res;
  }

  std::cout << a << "\t" << b << std::endl;

  ofs << res;

  return 0;
}
