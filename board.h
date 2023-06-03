#ifndef BOARD_H 
#define BOARD_H 

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;


class board {
    player snake;
    juice snake_juice;
    char grid[board_size][board_size];
    
    public:
    bool game_over = false; 
    board() {
        grid[snake.get_y_pos_of_head()][snake.get_x_pos_of_head()] = 1;
    }
    void print_board() {
        if (game_over == false) {
            for(int i = 0; i < board_size; i++){
                for(int j = 0; j < board_size; j++){
                    grid[i][j] = '.';
                }
            }
            // Paint snake on grid
            vector<pair<pair<int, int>, direction>> snake_body = snake.get_snake_body();
            for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
                grid[(*iter).first.second][(*iter).first.first] = 'S';
            }
            // Paint juice on grid
            pair<int,int> juice_location = snake_juice.get_juice();
            grid[juice_location.second][juice_location.first] = 'X'; 

            for(int i = 0; i < board_size; i++){
                for(int j = 0; j < board_size; j++){
                    cout << grid[i][j] << "  ";
                }
            cout << endl;
            }
        } else {
            cout << endl << endl << endl << "      GAME OVER" << endl;
            cout << endl << endl << endl;
        }
    } 
    void print_player_info() {
        if (game_over == false) {
            cout << "Head of Snake at: " << snake.get_x_pos_of_head() + 1 << ", " << snake.get_y_pos_of_head() + 1 << endl;
            cout << "Snake length is : " << snake.get_length() << endl;
        }
    }
    void set_direction_of_head(direction movement) {
        int snake_direction = snake.get_snake_head_direction();
        if (snake_direction == direction::left && movement == direction::right)
            return;
        else if (snake_direction == direction::right && movement == direction::left)
            return;
        else if (snake_direction == direction::up && movement == direction::down)
            return;
        else if (snake_direction == direction::down && movement == direction::up)
            return;
        
        snake.set_direction_of_snake_head(movement);
    }
    void handle_snake_movement(){
        snake.move();
        if (snake.body_overlapping() == true || snake.head_out_of_bounds() == true)
            game_over = true;
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
    void propagate_snake_behavior() {
        snake.propagate_snake_behavior();
    }
        
};

#endif /* BOARD_H */
