#include "JednorekiBandyta.h"
#include <iostream>
#include <cstdlib>


using namespace std;



JednorekiBandyta::JednorekiBandyta(){
    one_game_cost = nullptr;
    percent_to_pot = nullptr;
    win_probability = nullptr;
    pot = new int(0);
    game_count = new int(0);
}

JednorekiBandyta::JednorekiBandyta(int one_game_cost){
    this -> one_game_cost = new int(one_game_cost);
    percent_to_pot = nullptr;
    win_probability = nullptr;
    pot = new int(0);
    game_count = new int(0);
}

JednorekiBandyta::JednorekiBandyta( JednorekiBandyta & jednorekiBandyta ){
    one_game_cost = new int(*jednorekiBandyta.one_game_cost);
    percent_to_pot = new int(*jednorekiBandyta.percent_to_pot);
    win_probability = new float(*jednorekiBandyta.win_probability);
    pot = new int(*jednorekiBandyta.pot );
    game_count = new int(*jednorekiBandyta.game_count);
}
JednorekiBandyta::JednorekiBandyta( JednorekiBandyta && jednorekiBandyta ){
    one_game_cost = jednorekiBandyta.one_game_cost;
    percent_to_pot = jednorekiBandyta.percent_to_pot;
    win_probability = jednorekiBandyta.win_probability;
    pot = jednorekiBandyta.pot;
    game_count = jednorekiBandyta.game_count;
}

JednorekiBandyta::~JednorekiBandyta(){
    if( one_game_cost != nullptr )
        delete one_game_cost;
    if( percent_to_pot != nullptr )
        delete percent_to_pot;
    if( win_probability != nullptr )
        delete win_probability;
    if( pot != nullptr )
        delete pot;
    if( game_count != nullptr )
        delete game_count;
    
}
void JednorekiBandyta::set_one_game_cost(int one_game_cost){
    if ( one_game_cost <= 0){
        return;
    }
    this -> one_game_cost = new int(one_game_cost);
}

int JednorekiBandyta::get_one_game_cost(){
    return *one_game_cost;
}

void JednorekiBandyta::set_percent_to_pot(int percent_to_pot){
    if ( (percent_to_pot < 1) || (percent_to_pot > 70) ){
        return;
    }
    this -> percent_to_pot = new int(percent_to_pot);
}

int JednorekiBandyta::get_percent_to_pot(){

    return *percent_to_pot;
}

int JednorekiBandyta::get_pot(){

    return *pot;
}

void JednorekiBandyta::set_win_probability(float win_probability){
    if ( (win_probability < 0.1) || (win_probability > 0.2) ){
        return;
    }
    this -> win_probability = new float(win_probability);
}

GameResult JednorekiBandyta::play_game(){
    GameResult game_result;
    game_result.pot = *pot;
    
    int r = rand() % 1000;
    float f = (float) r / (float) 1000;
    if ( f <= *win_probability){
        game_result.win = true;
        *pot = 0;
    }else{
        game_result.win = false;
        *pot += (int) ( (*one_game_cost * *percent_to_pot) / 100);
    }
    *game_count ++;
    return game_result;
}
