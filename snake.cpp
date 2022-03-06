#include <iostream>
#include <stdlib.h>
#include "game.h"

int main() {

    game test_game;
    test_game.print_game();
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.control_player(direction::down);
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.control_player(direction::left);
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.control_player(direction::down);
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.control_player(direction::right);
    test_game.increment_game_time();
    test_game.increment_game_time();
    test_game.increment_game_time();

    return 0;
}