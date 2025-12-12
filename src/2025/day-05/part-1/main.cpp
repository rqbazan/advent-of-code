#include <iostream>
#include <vector>
#include <sstream>
#define __test__

using namespace std;

typedef long long ll;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  vector<pair<ll, ll>> ranges;
  string line;
  ll id, start, end;
  char dash;

  while (getline(cin, line) && !line.empty())
  {
    stringstream ss(line);
    ss >> start >> dash >> end;
    ranges.push_back({start, end});
  }

  sort(ranges.begin(), ranges.end());

  int valid = 0;
  while (cin >> id)
  {
    for (const auto &range : ranges)
    {
      if (id >= range.first && id <= range.second)
      {
        valid++;
        break;
      }
    }
  }

  cout << valid << endl;

  return 0;
}
