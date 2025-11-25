#include <iostream>
#include <vector>
#include <algorithm>

bool dfs(const std::vector<std::vector<int>>& adj, std::vector<int>& colors, int v)
{
  for (int child : adj[v]) {
    if (colors[child] == 0) {
      colors[child] = (colors[v] == 1) ? 2 : 1;
      if (!dfs(adj, colors, child)) return false;
    } else if (colors[child] == colors[v]) {
      return false;
    }
  }
  return true;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> colors(n, 0);

  for (int i = 0; i < n; ++i) {
    if (colors[i] == 0) {
      colors[i] = 1;
      if (!dfs(adj, colors, i)) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
      }
    }
  }

  std::for_each(colors.begin(), colors.end(), [](int i) { std::cout << i << " "; });
  std::cout << std::endl;

  return 0;
}
