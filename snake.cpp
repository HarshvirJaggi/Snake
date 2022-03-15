#include <iostream>
#include <stdlib.h>
#include "game.h"

using namespace std;

int main() {

    char input;
    game test_game;
    do
    {
        cout << "\033[2J\033[1;1H";
        test_game.increment_game_time();
        cin >> input;
        if (input == 'w'){
            test_game.control_player(direction::up);
        }
        else if (input == 'a')
        {
            test_game.control_player(direction::left);
        }
        else if (input == 's')
        {
            test_game.control_player(direction::down);
        }
        else if (input == 'd')
        {
            test_game.control_player(direction::right);
        }
        else
            continue;
    }
    while(input != 'x');

    return 0;
}
