#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
#define __test__

using namespace std;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  int sum_total = 0;

  while (getline(cin, line))
  {
    istringstream iss(line);

    int card_id;
    set<int> winner_numbers, my_numbers;

    iss.ignore(4); // "Card"
    iss >> card_id;
    iss.ignore(1); // ":"

    while (!iss.eof())
    {
      string maybe_num;
      iss >> maybe_num;

      if (maybe_num == "|")
        break;

      int num = stoi(maybe_num);
      winner_numbers.insert(num);
    }

    while (!iss.eof())
    {
      string maybe_num;
      iss >> maybe_num;

      if (maybe_num == "|")
        break;

      int num = stoi(maybe_num);
      my_numbers.insert(num);
    }

    set<int> intersect;
    set_intersection(winner_numbers.begin(), winner_numbers.end(),
                     my_numbers.begin(), my_numbers.end(),
                     inserter(intersect, intersect.begin()));

    int power = intersect.size() - 1;
    if (power >= 0)
      sum_total += pow(2, power);
  }

  cout << sum_total << endl;

  return 0;
}
