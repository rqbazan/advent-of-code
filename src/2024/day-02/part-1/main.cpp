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

    bool is_safe = true;
    for (size_t i = 1; i < report.size(); i++)
    {
      int diff = abs(report[i - 1] - report[i]);
      bool is_safe = diff <= 1 && diff <= 3;

      if (!is_safe)
        break;
    }

    if (is_safe)
      total_safe_reports++;
  }

  cout << total_safe_reports << endl;

  return 0;
}
