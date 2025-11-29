#include <algorithm>
#include <fstream>
#include <vector>

void dfs(int par, int& nodes, std::vector<bool>& visited, const std::vector<bool>& closed, const std::vector<std::vector<int>>& adj)
{
  if (visited[par] || closed[par]) return;

  ++nodes;
  visited[par] = true;

  for (int child : adj[par]) {
    if (!visited[child]) dfs(child, nodes, visited, closed, adj);
  }
}

int main()
{
  std::ifstream ifs("closing.in");
  std::ofstream ofs("closing.out");

  int n, m;
  ifs >> n >> m;

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    ifs >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> closing_order(n);
  for (int i = 0; i < n; ++i) {
   ifs >> closing_order[i];
   --closing_order[i];
  }

  int nodes = 0;
  std::vector<bool> visited(n, false);
  std::vector<bool> closed(n, false);
  dfs(0, nodes, visited, closed, adj);

  ofs << (nodes == n ? "YES" : "NO") << std::endl;

  for (int i = 0; i < n - 1; ++i) {
    nodes = 0;
    closed[closing_order[i]] = true;
    std::fill(visited.begin(), visited.end(), false);

    dfs(closing_order[n - 1], nodes, visited, closed, adj);

    ofs << (nodes == n - i - 1 ? "YES" : "NO") << std::endl;
  }

  return 0;
}
