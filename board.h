#ifndef BOARD_H 
#define BOARD_H 

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

const int length = 10;

class board {
    player snake;
    int grid[length][length] = {0}; 
    
    public:
    board() {
        grid[snake.get_y_pos_of_head()][snake.get_x_pos_of_head()] = 1;
    }
    void print_board() {
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                grid[i][j] = 0;
            }
        }

        vector<pair<pair<int, int>, direction>> snake_body = snake.get_snake_body();
        for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
            grid[(*iter).first.second][(*iter).first.first] = 1;
        }

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout << grid[i][j] << "  ";
            }
        cout << endl;
        }
    } 
    void print_player_info() {
        cout << "Head of Snake at: " << snake.get_x_pos_of_head() + 1 << ", " << snake.get_y_pos_of_head() + 1 << endl;
        cout << "Snake length is : " << snake.get_length() << endl;
    }
    void set_direction_of_head(direction movement) {
        snake.set_direction_of_snake_head(movement);
    }
    void increment_time(){
        snake.move();
    }
        
};

#endif /* BOARD_H */
