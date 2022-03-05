#ifndef GAME_H 
#define GAME_H 

#include <iostream>
#include "board.h"

using namespace std;



class game {
    board my_board;
    public:
    void print_game() {
        my_board.print_board();
        my_board.print_player_info();
    }
    void control_player(direction movement){
        my_board.set_direction_of_head(movement);
    }
    void increment_game_time(){
        my_board.increment_time();
        my_board.print_board();
        my_board.print_player_info();
    }
};

#endif /* GAME_H */