#include <iostream>
#include <vector>
#include <math.h>
#define __test__

using namespace std;

const short adjacent_dir_row[] = {-1, 0, 1, -1, 0, 1};
const short adjacent_dir_col[] = {-1, -1, -1, 1, 1, 1};

inline bool is_number(char c)
{
  return c >= '0' && c <= '9';
}

inline short to_number(char c)
{
  return c - '0';
}

inline short count_digits(int num)
{
  return floor(log10(num) + 1);
}

inline bool is_coord_valid(int i, int j, int num_rows, int num_cols)
{
  return i >= 0 && i < num_rows && j >= 0 && j < num_cols;
}

inline bool is_symbol(char c)
{
  return !is_number(c) && c != '.';
}

bool check_if_has_adjacent_symbol(vector<string> &lines, int row, int col1, int col2)
{
  int num_rows = lines.size();
  int num_cols = lines[0].size();

  for (int k = 0; k < 6; k++)
  {
    int col = k < 3 ? col1 : col2;

    int ad_i = row + adjacent_dir_row[k];
    int ad_j = col + adjacent_dir_col[k];

    if (is_coord_valid(ad_i, ad_j, num_rows, num_cols))
    {
      char ad_digit = lines[ad_i][ad_j];

      if (is_symbol(ad_digit))
        return true;
    }
  }

  int ad_i, ad_j;
  for (int k = col1; k <= col2; k++)
  {
    ad_i = row - 1;
    ad_j = k;

    if (is_coord_valid(ad_i, ad_j, num_rows, num_cols))
    {
      char ad_digit = lines[ad_i][ad_j];

      if (is_symbol(ad_digit))
        return true;
    }

    ad_i = row + 1;
    ad_j = k;

    if (is_coord_valid(ad_i, ad_j, num_rows, num_cols))
    {
      char ad_digit = lines[ad_i][ad_j];

      if (is_symbol(ad_digit))
        return true;
    }
  }

  return false;
}

int extract_num(vector<vector<bool>> &visited, vector<string> &lines, int i, int j)
{
  int num = 0, len = lines[i].size();

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
  vector<vector<bool>> visited;

  while (getline(cin, line))
  {
    lines.push_back(line);
    visited.push_back(vector<bool>(line.size(), false));
  }

  int num_rows = lines.size();
  int num_cols = lines[0].size();
  int sum_total = 0;

  int i = 0;
  while (i < num_rows)
  {
    int j = 0;
    while (j < num_cols)
    {
      char digit = lines[i][j];

      if (is_number(digit) && !visited[i][j])
      {
        int num = extract_num(visited, lines, i, j);

        cout << "extract_num: " << num << endl;

        int jj = j + count_digits(num) - 1;
        bool is_num_valid = check_if_has_adjacent_symbol(lines, i, j, jj);

        if (is_num_valid)
          sum_total += num;

        cout << "(" << i << ", " << j << ")"
             << " ... "
             << "(" << i << ", " << jj << ")"
             << " is_valid: " << is_num_valid << "\n\n";
      }
      j++;
    }
    i++;
  }

  cout << sum_total << endl;

  return 0;
}