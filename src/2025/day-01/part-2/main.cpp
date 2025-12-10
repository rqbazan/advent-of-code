#include <iostream>
#define __test__

using namespace std;

int abs_mod(int i, int n)
{
  return (i % n + n) % n;
}

struct Dial
{
  int position, zero_clicks;

  Dial() : position(50), zero_clicks(0) {}

  void to_right(int steps)
  {
    zero_clicks += (position + steps) / 100;
    position = abs_mod(position + steps, 100);
  }

  void to_left(int steps)
  {
    if (position == 0)
      zero_clicks += steps / 100;
    else if (steps > position)
      zero_clicks += 1 + ((steps - position - 1) / 100);

    position = abs_mod(position - steps, 100);
    if (position == 0)
      zero_clicks += 1;
  }
};

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  char dir;
  int steps;
  Dial dial = Dial();

  while (cin >> dir >> steps)
  {
    // cout << "current dial: " << dial.position << endl;
    // cout << "direction: " << dir << ", steps: " << steps << endl;
    if (dir == 'R')
    {
      dial.to_right(steps);
      // cout << "to right: " << dial.position << endl;
    }
    else if (dir == 'L')
    {
      dial.to_left(steps);
      // cout << "to left: " << dial.position << endl;
    }

    // cout << "zero clicks so far: " << dial.zero_clicks << endl;
    // cout << "------------------------" << endl;
  }

  cout << dial.zero_clicks << endl;

  return 0;
}
