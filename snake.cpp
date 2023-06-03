#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <chrono>
#include <thread>
#include "game.h"

using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 0;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int main() {

    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    char input;
    game test_game;
    do
    {
        cout << "\033[2J\033[1;1H";
        test_game.increment_game_time();
        if (test_game.is_game_over() == true)
            return 0;

        sleep_for(nanoseconds(800000000));
        input = getch();
        if (input == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                input = 'w';
                break;
                case 'B':
                input = 's';
                break;
                case 'C':
                input = 'd';
                break;
                case 'D':
                input = 'a';
                break;
            }
        }

        if (input == 'w'){
            test_game.control_player(direction::up);
        }
        else if (input == 'a')
        {
            test_game.control_player(direction::left);
        }
        else if (input == 's' || input == KEY_DOWN)
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
