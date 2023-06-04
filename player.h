#ifndef PLAYER_H 
#define PLAYER_H 

#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include <vector>
#include <unordered_map>

using namespace std;

enum direction {left, right, up, down};
const int board_size = 25;
//srand(time(NULL));

class player {
    int length;
    vector<pair<pair<int, int>, direction>> snake_body;
    public:
    player() {
        //srand(time(NULL));
        //snake_body.push_back(make_pair(make_pair((rand() % (length-1)) + 1,(rand() % (length-1)) + 1), direction::left));
        snake_body.push_back(make_pair(make_pair(10,2), direction::left));
        snake_body.push_back(make_pair(make_pair(11,2), direction::left));
        snake_body.push_back(make_pair(make_pair(12,2), direction::left));
        length = 3;
    }
    int get_x_pos_of_head() { return snake_body.front().first.first;}
    int get_y_pos_of_head() { return snake_body.front().first.second;}
    int get_snake_head_direction() { return snake_body.front().second;}
    int get_length() { return length;}
    void set_direction_of_snake_head(direction movement) {snake_body.front().second = movement;}
    void eat() {
        length++;
        pair<pair<int, int>, direction> current_end = snake_body.back();

        if (snake_body.back().second == direction::left){
            current_end.first.first = current_end.first.first + 1;
        }
        else if (snake_body.back().second == direction::right)
        {
            current_end.first.first = current_end.first.first - 1;
        }
        else if (snake_body.back().second == direction::up)
        {
            current_end.first.second = current_end.first.second + 1;
        }
        else if (snake_body.back().second == direction::down)
        {
            current_end.first.second = current_end.first.second - 1;
        }

        snake_body.push_back(current_end);
        
    }
    void move() {
        for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
            
            if((*iter).second == direction::left) {
                (*iter).first.first--;
            }
            else if ((*iter).second == direction::right)
            {
                (*iter).first.first++;
            }
            else if ((*iter).second == direction::up)
            {
                (*iter).first.second--;
            }
            else if ((*iter).second == direction::down)
            {
                (*iter).first.second++;
            }
        }
    }
    bool body_overlapping() {
        unordered_map<string, int> coordinate_map;
        for (auto snake_node : snake_body){
            string position_as_string = to_string(snake_node.first.first) + "," + to_string(snake_node.first.second);
            if (coordinate_map.find(position_as_string) == coordinate_map.end()) {
                coordinate_map[position_as_string] = 1;
            } else {
                return true;
            }
        }
        return false;
        
    }
    vector<pair<pair<int, int>, direction>> get_snake_body() {
        return snake_body;
    }
    void propagate_snake_behavior() {
        int i = 0;
        auto second_el = snake_body.begin() + 1; 
        for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.end(); iter-- != second_el; ){
            if ((*iter).second != (*prev(iter)).second) {
                (*iter).second = (*prev(iter)).second;
            }
        }
    }
};

class juice {
    pair<int,int> juice_loc; 
    public:
    juice() {
        juice_loc.first = 5;
        juice_loc.second = 1 + 1;
    }
    pair<int,int> get_juice(){
        return juice_loc;
    }
    void randomize() {
        juice_loc.first = (rand() % (board_size-1)) + 1;
        juice_loc.second = (rand() % (board_size-1)) + 1;
    }
};
#endif /* PLAYER_H */