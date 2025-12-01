#include <fstream>
#include <vector>
#include <iostream>

void dfs(std::vector<std::vector<char>>& grid, int x, int y, int& perim, int& area)
{
  if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size()) return;
  if (grid[x][y] != '#') return;

  area += 1;
  grid[x][y] = 'A';

  static std::vector<std::pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (const auto & d : dirs) {
    int nx = x + d.first, ny = y + d.second;
    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[x].size() || grid[nx][ny] == '.') {
      ++perim;
    } else if (grid[nx][ny] == '#') {
      dfs(grid, nx, ny, perim, area);
    }
  }
}

int main()
{
  std::ifstream ifs("perimeter.in");
  std::ofstream ofs("perimeter.out");

  int n;
  ifs >> n;
  std::vector<std::vector<char>> grid(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ifs >> grid[i][j];
    }
  }

  int best_area = 0, best_perim = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '#') {
        int area = 0, perim = 0;
        dfs(grid, i, j, perim, area);

        if (area > best_area || (area == best_area && perim < best_perim)) {
          best_area = area;
          best_perim = perim;
        }
      }
    }
  }

  ofs << best_area << ' ' << best_perim << std::endl;

  return 0;
}
