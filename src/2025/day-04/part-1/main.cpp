#include <iostream>
#include <vector>
#define __test__

using namespace std;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  vector<string> matrix;
  string line;

  short dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  short dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while (getline(cin, line))
    matrix.push_back(line);

  int rows = matrix.size();
  int cols = matrix[0].size();
  int total = 0;

  for (size_t i = 0; i < rows; ++i)
    for (size_t j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == '.')
        continue;

      int adjacents = 0;
      for (size_t d = 0; d < 8; ++d)
      {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x >= 0 && x < rows && y >= 0 && y < cols)
          if (matrix[x][y] == '@')
            adjacents++;

        if (adjacents > 3)
          break;
      }

      if (adjacents <= 3)
        total += 1;
    }

  cout << total << endl;

  return 0;
}
