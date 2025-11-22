#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int start)
{
  visited[start] = true;
  for (const auto& u : adj[start]) {
    if (!visited[u]) dfs(adj, visited, u);
  }
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

  std::vector<bool> visited(n, false);
  std::vector<int> new_roads;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(adj, visited, i);
      new_roads.push_back(i);
    }
  }

  std::cout << new_roads.size() - 1 << std::endl;
  for (int i = 1; i < new_roads.size(); ++i) {
    std::cout << new_roads[i - 1] + 1 << " " << new_roads[i] + 1 << std::endl;
  }

  return 0;
}
