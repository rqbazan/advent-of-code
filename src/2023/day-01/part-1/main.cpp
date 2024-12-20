#include <iostream>
#define __test__

using namespace std;

inline bool is_number(char c)
{
  return c >= '0' && c <= '9';
}

inline int to_number(char c)
{
  return c - '0';
}

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  int sumTotal = 0;

  while (cin >> line)
  {
    string::iterator beginIterator = line.begin();
    string::iterator endIterator = line.end() - 1;
    short firstDigit = -1, secondDigit = -1;

    while (beginIterator <= endIterator)
    {
      char beginChar = *beginIterator, endChar = *endIterator;

      if (firstDigit == -1)
      {
        if (is_number(beginChar))
          firstDigit = to_number(beginChar);
        else
          beginIterator++;
      }

      if (secondDigit == -1)
      {
        if (is_number(endChar))
          secondDigit = to_number(endChar);
        else
          endIterator--;
      }

      if (firstDigit != -1 && secondDigit != -1)
        break;
    }

    short numInLine = firstDigit * 10 + secondDigit;
    sumTotal += numInLine;

    cout << line << ": " << numInLine << endl;
  }

  cout << sumTotal;

  return 0;
}