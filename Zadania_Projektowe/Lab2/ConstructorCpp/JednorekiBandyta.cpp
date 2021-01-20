#include "JednorekiBandyta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Logger.h"
#include "Stopper.h"

using namespace std;



JednorekiBandyta::JednorekiBandyta():Logger(true){
    log("Konstruktor pusty");
    reset();
    one_game_cost = nullptr;
    percent_to_pot = nullptr;
    win_probability = nullptr;
    pot = new int(0);
    game_count = new int(0);
}

JednorekiBandyta::JednorekiBandyta(int one_game_cost):Logger(true){
    log("Konstruktor konwertujący");
    reset();
    this -> one_game_cost = new int(one_game_cost);
    percent_to_pot = nullptr;
    win_probability = nullptr;
    pot = new int(0);
    game_count = new int(0);
}

JednorekiBandyta::JednorekiBandyta( JednorekiBandyta & jednorekiBandyta ):Logger(true){
    log("Konstruktor kopiujący");
    reset();
    one_game_cost = new int(*jednorekiBandyta.one_game_cost);
    percent_to_pot = new int(*jednorekiBandyta.percent_to_pot);
    win_probability = new float(*jednorekiBandyta.win_probability);
    pot = new int(*jednorekiBandyta.pot );
    game_count = new int(*jednorekiBandyta.game_count);
}
JednorekiBandyta::JednorekiBandyta( JednorekiBandyta && jednorekiBandyta ):Logger(true){
    log("Konstruktor przenoszący");
    reset();
    one_game_cost = jednorekiBandyta.one_game_cost;
    percent_to_pot = jednorekiBandyta.percent_to_pot;
    win_probability = jednorekiBandyta.win_probability;
    pot = jednorekiBandyta.pot;
    game_count = jednorekiBandyta.game_count;
}

JednorekiBandyta::~JednorekiBandyta(){
    log("Dekontruktor");
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
    start();
    log("Zmiana stawki");
    if ( one_game_cost <= 0){
        return;
    }
    this -> one_game_cost = new int(one_game_cost);
    stop();
}

int JednorekiBandyta::get_one_game_cost(){
    start();
    log("Sprawdzenie stawki");
    stop();
    return *one_game_cost;
}

void JednorekiBandyta::set_percent_to_pot(int percent_to_pot){
    start();
    log("Zmiana procentu do puli");
    if ( (percent_to_pot < 1) || (percent_to_pot > 70) ){
        stop();
        return;
    }
    this -> percent_to_pot = new int(percent_to_pot);
    stop();
}

int JednorekiBandyta::get_percent_to_pot(){
    start();
    log("Sprawdzenie procentu do puli");
    stop();
    return *percent_to_pot;
}

void JednorekiBandyta::set_win_probability(float win_probability){
    start();
    log("Zmiana prawd. wygranej");
    if ( (win_probability < 0.1) || (win_probability > 0.2) ){
        stop();
        return;
    }
    this -> win_probability = new float(win_probability);
    stop();
}

GameResult JednorekiBandyta::play_game(){
    start();
    log("Zagranie");
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
    stop();
    return game_result;
}
