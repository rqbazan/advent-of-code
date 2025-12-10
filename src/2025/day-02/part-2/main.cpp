#include <iostream>
#include <sstream>
#define __test__

using namespace std;

typedef long long ll;

bool is_invalid(ll n)
{
  string s = to_string(n);

  for (size_t slices = 2; slices <= s.size(); ++slices)
  {
    if (s.size() % slices != 0)
      continue;

    size_t part_size = s.size() / slices;
    bool all_parts_equal = true;
    for (size_t j = 1; j < slices; ++j)
    {
      size_t prev_index = (j - 1) * part_size;
      size_t start_index = j * part_size;
      if (s.substr(prev_index, part_size) != s.substr(start_index, part_size))
      {
        all_parts_equal = false;
        break;
      }
    }
    if (all_parts_equal)
      return true;
  }

  return false;
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
