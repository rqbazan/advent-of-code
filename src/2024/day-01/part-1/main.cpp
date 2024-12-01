#include <iostream>
#include <algorithm>
#include <vector>
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
  vector<int> left_numbers, right_numbers;

  while (getline(cin, line))
  {
    int left_num, right_num;
    istringstream iss(line);

    iss >> left_num;
    iss >> right_num;

    left_numbers.push_back(left_num);
    right_numbers.push_back(right_num);
  }

  sort(left_numbers.begin(), left_numbers.end());
  sort(right_numbers.begin(), right_numbers.end());

  int total_distance = 0;
  int total_left_numbers = left_numbers.size();

  for (int i = 0; i < total_left_numbers; i++)
  {
    int distance = abs(left_numbers[i] - right_numbers[i]);
    cout << left_numbers[i] << " " << right_numbers[i] << ": " << distance << endl;
    total_distance += distance;
  }

  cout << total_distance << endl;

  return 0;
}
