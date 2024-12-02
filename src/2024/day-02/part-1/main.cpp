#include <iostream>
#include <sstream>
#define __test__

using namespace std;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string line;
  int total_safe_reports = 0;

  while (getline(cin, line))
  {
    int num;
    istringstream iss(line);
    vector<int> report;

    while (iss >> num)
      report.push_back(num);

    bool is_safe = true,
         is_all_decreasing = report[0] < report[1];

    for (size_t i = 1; i < report.size(); i++)
    {
      int distance = abs(report[i - 1] - report[i]);

      bool is_valid_distance = distance >= 1 && distance <= 3;
      bool is_decreasing = report[i - 1] < report[i];

      if (!is_valid_distance || is_all_decreasing != is_decreasing)
      {
        is_safe = false;
        break;
      }
    }

    if (is_safe)
      total_safe_reports++;
  }

  cout << total_safe_reports << endl;

  return 0;
}
