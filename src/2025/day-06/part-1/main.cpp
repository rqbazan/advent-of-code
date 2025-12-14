#include <iostream>
#include <sstream>
#include <vector>
#define __test__

using namespace std;

typedef unsigned long long ll;

bool is_operators(const string &line)
{
  for (char c : line)
    if (c == '+' || c == '*')
      return true;
  return false;
}

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  vector<vector<ll>> matrix;

  while (getline(cin, line) && !is_operators(line))
  {
    istringstream iss(line);
    vector<ll> row;
    ll value;

    while (iss >> value)
      row.push_back(value);

    matrix.push_back(row);
  }

  istringstream iss(line);
  char symbol;
  vector<char> operators;

  while (iss >> symbol)
    operators.push_back(symbol);

  ll total = 0;
  for (size_t i = 0; i < operators.size(); ++i)
  {
    char op = operators[i];
    ll result = op == '+' ? 0 : (op == '*' ? 1 : 0);

    for (size_t r = 0; r < matrix.size(); ++r)
    {
      if (op == '+')
        result += matrix[r][i];
      else if (op == '*')
        result *= matrix[r][i];
    }
    total += result;
  }

  cout << total << endl;

  return 0;
}
