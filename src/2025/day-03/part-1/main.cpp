#include <iostream>
#define __test__

using namespace std;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  int joltage = 0;
  while (getline(cin, line))
  {
    short max_left_digit = 0, max_left_digit_index = -1;
    for (size_t i = 0; i < line.size() - 1; ++i)
    {
      short digit = line[i] - '0';
      if (digit > max_left_digit)
      {
        max_left_digit = digit;
        max_left_digit_index = i;
      }
    }

    short max_right_digit = 0;
    for (size_t i = max_left_digit_index + 1; i < line.size(); ++i)
    {
      short digit = line[i] - '0';
      if (digit > max_right_digit)
      {
        max_right_digit = digit;
      }
    }

    joltage += max_left_digit * 10 + max_right_digit;
  }

  cout << joltage << endl;

  return 0;
}
