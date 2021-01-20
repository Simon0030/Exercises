#include <iostream>
#include <string>
#include "JednorekiBandyta.h"
#include "JednorekiBandyta.cpp"

using namespace std;

int main () {
    JednorekiBandyta jednorekiBandyta;
    jednorekiBandyta.set_one_game_cost(10);
    jednorekiBandyta.set_percent_to_pot(50);
    jednorekiBandyta.set_win_probability(0.15);
    string action = "";
    while (action != "exit"){
        cout << "Podaj akcję: (zagraj, stawka, pula) " <<endl;
        cin >> action ;
        if (action=="zagraj"){
            GameResult result = jednorekiBandyta.play_game();
            if (result.win){
                cout << "Wygrałeś " << result.pot << "PLN" << endl;
            }else{
                cout << "Przegrałeś " << jednorekiBandyta.get_one_game_cost() << "PLN" << endl;
            }
        }else if (action == "stawka"){
            cout << "Stawka to: " << jednorekiBandyta.get_one_game_cost() << "PLN"<< endl;
        }else if (action == "pula"){
            cout << "Pula to: " << jednorekiBandyta.get_pot() << "PLN"<< endl;
        }
    }
    
}