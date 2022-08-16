#include <iostream>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"

using namespace std;

int main() {
    initscr();			/* Start curses mode 		  */
    //cbreak();
    timeout(2000);
    int input;
    game test_game;
    direction last_direction = direction::left;

    do
    {
        test_game.increment_game_time();
        refresh();
        input = getch();

        if (input == int('w')){
            test_game.control_player(direction::up);
            last_direction = direction::up;
        }
        else if (input == int('a'))
        {
            test_game.control_player(direction::left);
            last_direction = direction::left;
        }
        else if (input == int('s'))
        {
            test_game.control_player(direction::down);
            last_direction = direction::down;
        }
        else if (input == int('d'))
        {
            test_game.control_player(direction::right);
            last_direction = direction::right;
        }
        else if (input == ERR)
        {
            test_game.control_player(last_direction);
        }
        clear();
    }
    while(input != int('x'));

	endwin();			/* End curses mode		  */

    return 0;
}
