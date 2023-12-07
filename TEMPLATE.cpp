#include <iostream>
#define __test__

using namespace std;

int main()
{
#ifdef __test__
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  /** code **/

  return 0;
}
