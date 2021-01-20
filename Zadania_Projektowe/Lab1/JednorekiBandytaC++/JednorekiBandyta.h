#ifndef JEDNOREKIBANDYTA_H
#define JEDNOREKIBANDYTA_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct GameResult{
     bool win;
     int pot;
};


class JednorekiBandyta {
    private:
        int* one_game_cost;
        int* percent_to_pot;
        float* win_probability;
        int* pot;
        int* game_count;

    public:
        JednorekiBandyta();
        JednorekiBandyta(int one_game_cost);
        JednorekiBandyta( JednorekiBandyta & jednorekiBandyta );
        JednorekiBandyta( JednorekiBandyta && jednorekiBandyta );
        ~JednorekiBandyta();
        void set_one_game_cost(int one_game_cost);
        int get_one_game_cost();
        void set_percent_to_pot(int percent_to_pot);
        int get_percent_to_pot();
        int get_pot();
        void set_win_probability(float win_probability);
        GameResult play_game();

    };


#endif