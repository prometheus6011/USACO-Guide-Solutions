#include <iostream>
#include <set>

int main(void)
{
  int n;
  std::cin >> n;
  std::set<int> st;
  for (int i; std::cin >> i; ) {
    st.insert(i);
  }

  std::cout << st.size() << std::endl;

  return 0;
}
