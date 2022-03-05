#ifndef PLAYER_H 
#define PLAYER_H 

#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

enum direction {left, right, up, down};

class player {
    int length;
    vector<pair<pair<int, int>, direction>> snake_body;
    public:
    void eat() {length++;}
    player() {
        //srand(time(NULL));
        snake_body.push_back(make_pair(make_pair((rand() % 9) + 1,(rand() % 9) + 1), direction::left));
        length = 1;
    }
    int get_x_pos_of_head() { return snake_body.front().first.first;}
    int get_y_pos_of_head() { return snake_body.front().first.second;}
    int get_length() { return length;}
    void set_direction_of_snake_head(direction movement) {snake_body.front().second = movement;}

    void move() {
        for (vector<pair<pair<int, int>, direction>>::iterator iter = snake_body.begin(); iter != snake_body.end(); iter++){
            
            if((*iter).second == direction::left) {
                (*iter).first.first--;
            }
            else if ((*iter).first.second == direction::right)
            {
                (*iter).first.first++;
            }
            else if ((*iter).first.second == direction::up)
            {
                (*iter).first.second++;
            }
            else if ((*iter).first.second == direction::down)
            {
                (*iter).first.second--;
            }
        }
    }
    vector<pair<pair<int, int>, direction>> get_snake_body() {
        return snake_body;
    }
};

#endif /* PLAYER_H */