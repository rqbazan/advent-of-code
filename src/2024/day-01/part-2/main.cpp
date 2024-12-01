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

  int total_similarity_score = 0;
  int total_left_numbers = left_numbers.size();
  int total_right_numbers = right_numbers.size();

  int j = 0;
  for (int i = 0; i < total_left_numbers; i++)
  {
    int left_num = left_numbers[i];
    int view_times = 0;

    while (j < total_right_numbers && left_num >= right_numbers[j])
    {
      if (left_num == right_numbers[j])
      {
        view_times++;
      }
      j++;
    }

    int similarity_score = left_num * view_times;
    cout << left_num << ": " << view_times << ", " << similarity_score << endl;
    total_similarity_score += similarity_score;
  }

  cout << total_similarity_score << endl;

  return 0;
}
