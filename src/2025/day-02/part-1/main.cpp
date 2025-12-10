#include <iostream>
#include <sstream>
#define __test__

using namespace std;

typedef long long ll;

bool is_invalid(ll n)
{
  string s = to_string(n);

  if (s.length() % 2 != 0)
    return false;

  string first_half = s.substr(0, s.length() / 2);
  string second_half = s.substr(s.length() / 2);
  return first_half == second_half;
}

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  ll sum = 0, range_from, range_to;
  char dash;
  string range;

  while (getline(cin, range, ','))
  {
    istringstream iss(range);
    iss >> range_from >> dash >> range_to;

    for (ll n = range_from; n <= range_to; ++n)
    {
      if (is_invalid(n))
        sum += n;
    }
  }

  cout << sum << endl;

  return 0;
}
