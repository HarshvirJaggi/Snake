#ifndef BOARD_H 
#define BOARD_H 

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

const int length = 10;

class board {
    player snake;
    juice snake_juice;
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
        // Paint snake on grid
        vector<pair<pair<int, int>, direction>> snake_body = snake.get_snake_body();
        for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
            grid[(*iter).first.second][(*iter).first.first] = 1;
        }
        // Paint juice on grid
        pair<int,int> juice_location = snake_juice.get_juice();
        grid[juice_location.second][juice_location.first] = 7; 

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
    void handle_snake_movement(){
        snake.move();
    }
    void handle_juice() {
        vector<pair<pair<int, int>, direction>> snake_body = snake.get_snake_body();
        if (snake_body.front().first == snake_juice.get_juice()){
            bool collision;
            do {
                collision = false;
                snake_juice.randomize();
                for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
                    pair<int, int> snake_body_member = (*iter).first;
                    if (snake_body_member == snake_juice.get_juice()){
                        collision = true;
                        break; 
                        }       
                    }
                }
            while (collision == true);
            snake.eat();    
        }
        else{
            return; 
        }
    }
        
};

#endif /* BOARD_H */
