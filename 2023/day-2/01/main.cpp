#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#define __test__

using namespace std;

map<string, int> BAG_CONFIGURATION = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
};

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif

    string line;
    int sum_id = 0;

    while(getline(cin, line))
    {
        int game_id;
        bool is_game_valid = true;

        istringstream iss(line);

        iss.ignore(4); // "Game"
        iss >> game_id;
        iss.ignore(1); // ":"

        while (!iss.eof())
        {
            char divider;
            string color_name;
            int num_cubes;

            do {
                iss >> num_cubes >> color_name;

                divider = color_name.back();
            
                if (divider == ',' || divider == ';') 
                    color_name.pop_back();

                int max_cubes = BAG_CONFIGURATION[color_name];

                if (num_cubes > max_cubes)
                {
                    is_game_valid = false;
                    break;
                }
            } while (divider == ',');
        }

        if (is_game_valid)
        {
            cout << "game_id: " << game_id << endl;
            sum_id += game_id;
        }
    }

    cout << sum_id << endl;

    return 0;
}