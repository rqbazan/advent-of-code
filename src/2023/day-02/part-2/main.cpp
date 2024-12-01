#include <iostream>
#include <map>
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
  int sum_id = 0;

  while (getline(cin, line))
  {
    int game_id;
    map<string, int> bag_config = {
        {"red", -1},
        {"green", -1},
        {"blue", -1},
    };

    istringstream iss(line);

    iss.ignore(4); // "Game"
    iss >> game_id;
    iss.ignore(1); // ":"

    while (!iss.eof())
    {
      char divider;
      string color_name;
      int num_cubes;

      do
      {
        iss >> num_cubes >> color_name;

        divider = color_name.back();

        if (divider == ',' || divider == ';')
          color_name.pop_back();

        bag_config[color_name] = max(bag_config[color_name], num_cubes);
      } while (divider == ',');
    }

    int game_power = bag_config["red"] * bag_config["green"] * bag_config["blue"];
    cout << "game_power: " << game_power << endl;
    sum_id += game_power;
  }

  cout << sum_id << endl;

  return 0;
}