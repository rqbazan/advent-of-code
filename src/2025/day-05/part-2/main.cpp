#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#define __test__

using namespace std;

typedef unsigned long long ll;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  vector<pair<ll, ll>> ranges;
  string line;
  ll start, end;
  char dash;

  while (getline(cin, line) && !line.empty())
  {
    stringstream ss(line);
    ss >> start >> dash >> end;
    ranges.push_back({start, end});
  }

  sort(ranges.begin(), ranges.end());

  ll total_valid = 0;
  size_t i = 0;

  while (i < ranges.size() - 1)
  {
    size_t ii = i;

    ll start = ranges[i].first,
       end = ranges[i].second;

    // start_a ... end_a | start_b ... end_b
    while (i < ranges.size() - 1 && ranges[i + 1].first <= end + 1)
    {
      end = max(end, ranges[i + 1].second);
      i++;
    }

    ll range_size = end - start + 1;
    total_valid += range_size;
    i++;
  }

  cout << total_valid << endl;

  return 0;
}
