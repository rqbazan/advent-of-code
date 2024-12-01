#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#define __test__

using namespace std;

const short adjacent_dir_row[] = {-1, 0, 1, -1, 0, 1, -1, 1};
const short adjacent_dir_col[] = {-1, -1, -1, 1, 1, 1, 0, 0};

map<pair<int, int>, vector<int>> cache;

inline bool is_number(char c)
{
  return c >= '0' && c <= '9';
}

inline short to_number(char c)
{
  return c - '0';
}

inline bool is_valid_coord(int i, int j, int num_rows, int num_cols)
{
  return i >= 0 && i < num_rows && j >= 0 && j < num_cols;
}

inline bool is_asterisk(char c)
{
  return c == '*';
}

int extract_num(vector<vector<bool>> &visited, vector<string> &lines, int i, int j)
{
  int num = 0, len = lines[i].size();

  while ((j - 1) >= 0 && is_number(lines[i][j - 1]))
    j--;

  while (j < len && is_number(lines[i][j]))
  {
    char digit = lines[i][j];
    num = num * 10 + to_number(digit);
    visited[i][j] = true;
    j++;
  }

  return num;
}

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  vector<string> lines;
  cache = map<pair<int, int>, vector<int>>();

  while (getline(cin, line))
    lines.push_back(line);

  int num_rows = lines.size();
  int num_cols = lines[0].size();
  int sum_total = 0;

  for (int i = 0; i < num_rows; i++)
  {
    for (int j = 0; j < num_cols; j++)
    {
      char digit = lines[i][j];

      if (!is_asterisk(digit))
        continue;

      auto visited = vector<vector<bool>>(num_rows, vector<bool>(num_cols, false));

      for (int k = 0; k < 8; k++)
      {
        int ad_i = i + adjacent_dir_row[k];
        int ad_j = j + adjacent_dir_col[k];

        if (!is_valid_coord(ad_i, ad_j, num_rows, num_cols))
          continue;

        char digit = lines[ad_i][ad_j];

        if (is_number(digit) && !visited[ad_i][ad_j])
        {
          int num = extract_num(visited, lines, ad_i, ad_j);
          cache[make_pair(i, j)].push_back(num);
        }
      }
    }
  }

  for (auto it = cache.begin(); it != cache.end(); it++)
  {
    auto coord = it->first;
    auto nums = it->second;

    if (nums.size() == 2)
    {
      cout << "(" << coord.first << ", " << coord.second << ") -> ";
      int ratio = nums[0] * nums[1];
      cout << nums[0] << " x " << nums[1] << " = " << ratio << endl;
      sum_total += ratio;
    }
  }

  cout << sum_total << endl;

  return 0;
}