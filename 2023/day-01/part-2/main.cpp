#include <iostream>
#include <vector>
#define __test__

using namespace std;

vector<string> WORDS = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
};

inline bool is_number(char c)
{
  return c >= '0' && c <= '9';
}

inline int to_number(char c)
{
  return c - '0';
}

bool has_word(string word, string::iterator beginIterator, string::iterator endIterator, short incrementBy = 1)
{
  string::iterator it = beginIterator;
  string::iterator end = endIterator;

  string::iterator wIt = incrementBy > 0 ? word.begin() : word.end() - 1;
  string::iterator wEnd = incrementBy > 0 ? word.end() : word.begin() - 1;

  while (it != end && wIt != wEnd)
  {
    if (*it != *wIt) return false;

    it += incrementBy;
    wIt += incrementBy;
  }
  
  return true;
}

short find_number(string::iterator beginIterator, string::iterator endIterator, short incrementBy = 1)
{
  string::iterator it = beginIterator;

  while (it != endIterator)
  {
    if (is_number(*it))
      return to_number(*it);

    for (short i = 0; i < WORDS.size(); i++)
    {
      string word = WORDS[i];
      if (has_word(word, it, endIterator, incrementBy))
        return i;
    }

    it += incrementBy;
  }

  return -1;
}

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif

    string line;
    int sumTotal = 0;

    while (cin >> line)
    {
        string::iterator beginIterator = line.begin();
        string::iterator endIterator = line.end() - 1;
        short firstDigit = NULL, secondDigit = NULL;

        while (beginIterator <= endIterator)
        {
            if (firstDigit == NULL)
            {
                short num = find_number(beginIterator, endIterator + 1);
                if (num != -1) firstDigit = num;
                else beginIterator++;
            }

            if (secondDigit == NULL)
            {
                short num = find_number(endIterator, beginIterator - 1, -1);
                if (num != -1) secondDigit = num;
                else endIterator--;
            }

            if (firstDigit != NULL && secondDigit != NULL) break;
        }

        short numInLine = firstDigit * 10 + secondDigit;
        sumTotal += numInLine;

        cout << line << ": " << numInLine << endl;
    }

    cout <<  sumTotal;

    return 0;
}