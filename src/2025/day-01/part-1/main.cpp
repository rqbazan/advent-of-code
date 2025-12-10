#include <iostream>
#define __test__

using namespace std;

int to_right(int start, int steps, int maximum)
{
  return (start + steps) % maximum;
}

int to_left(int start, int steps, int maximum)
{
  return (((start - steps) % maximum) + maximum) % maximum;
}

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  char dir;
  int steps, dial = 50, zero_times = 0;

  while (cin >> dir >> steps)
  {
    // cout << "current dial: " << dial << endl;
    // cout << "direction: " << dir << ", steps: " << steps << endl;
    if (dir == 'R')
    {
      dial = to_right(dial, steps, 100);
      // cout << "to right: " << dial << endl;
    }
    else if (dir == 'L')
    {
      dial = to_left(dial, steps, 100);
      // cout << "to left: " << dial << endl;
    }

    if (dial == 0)
    {
      zero_times += 1;
    }
  }

  cout << zero_times << endl;

  return 0;
}
