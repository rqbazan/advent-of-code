#include <iostream>
#define __test__

using namespace std;

typedef long long ll;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  ll joltage = 0;

  while (getline(cin, line))
  {
    ll multipler = 100000000000;
    short max_digit_index = -1;

    for (size_t d = 1; d <= 12; ++d)
    {
      short max_digit = 0, start_index = max_digit_index + 1;

      size_t i = start_index;
      while (i <= line.size() - 1 - (12 - d))
      {
        short digit = line[i] - '0';
        if (digit > max_digit)
        {
          max_digit = digit;
          max_digit_index = i;
        }
        ++i;
      }

      joltage += max_digit * multipler;
      multipler /= 10;
    }
  }

  cout << joltage << endl;

  return 0;
}
