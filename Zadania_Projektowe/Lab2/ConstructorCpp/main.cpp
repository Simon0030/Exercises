#include <iostream>
#include "JednorekiBandyta.h"
#include "JednorekiBandyta.cpp"

using namespace std;

void f_value(JednorekiBandyta jednorekiBandyta) {
    jednorekiBandyta.set_one_game_cost(jednorekiBandyta.get_one_game_cost() +1);
    cout << "-> Wartość w funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;

}

void f_const_ref(const JednorekiBandyta &jednorekiBandyta) {
    cout << "-> Nie można wywołać metod" << endl;
}

void f_ref(JednorekiBandyta &jednorekiBandyta) {
    jednorekiBandyta.set_one_game_cost(jednorekiBandyta.get_one_game_cost() +1);
    cout << "-> Wartość w funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
}

void f_R( JednorekiBandyta &&jednorekiBandyta) {
    jednorekiBandyta.set_one_game_cost(jednorekiBandyta.get_one_game_cost() +1);
    cout << "-> Wartość w funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
}


int main () {
    srand ( time(NULL) );
    JednorekiBandyta jednorekiBandyta;
    jednorekiBandyta.set_one_game_cost( 1 );
    jednorekiBandyta.set_percent_to_pot( 50 );
    jednorekiBandyta.set_win_probability( 0.19 );

    
    cout << "FUNKCJA PRZEZ WARTOŚĆ" << endl;
    cout << "1) Konstruktor kopiujący:" << endl;
    cout << "-> wartość przed funkcją: " << jednorekiBandyta.get_one_game_cost() << endl;
    f_value(jednorekiBandyta);
    cout << "-> wartość po funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
    cout << "2) Konstruktor przenoszący:" << endl;
    cout << "-> wartość przed funkcją: " << jednorekiBandyta.get_one_game_cost() << endl;
    f_value(move(jednorekiBandyta));
    cout << "-> wartość po funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
    cout << "3) Konstruktor 'konwertujący' :" << endl;
    f_value( JednorekiBandyta(1) );

    //Obserwacje: Zmiany występujące w funkcji nie wpływają na instację w programie main.

    cout << endl;

    cout << "FUNKCJA PRZEZ STAŁĄ REFERENCJĘ" << endl;
    cout << "1) Konstruktor kopiujący:" << endl;
    cout << "-> wartość przed funkcją: " << jednorekiBandyta.get_one_game_cost() << endl;
    f_const_ref(jednorekiBandyta);
    cout << "-> wartość po funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
    cout << "2) Konstruktor przenoszący:" << endl;
    cout << "-> wartość przed funkcją: " << jednorekiBandyta.get_one_game_cost() << endl;
    f_const_ref(move(jednorekiBandyta));
    cout << "-> wartość po funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
    cout << "3) Konstruktor 'konwertujący' :" << endl;
    f_const_ref( JednorekiBandyta(1) );

    //Obserwacje: nie można wywoływać metod klasy w funkcji w której przekazujemy przez stałą referencję.

    cout << endl;

    cout << "FUNKCJA PRZEZ REFERENCJĘ" << endl;
    cout << "1) Konstruktor kopiujący:" << endl;
    cout << "-> wartość przed funkcją: " << jednorekiBandyta.get_one_game_cost() << endl;
    f_ref(jednorekiBandyta);
    cout << "-> wartość po funkcji: " << jednorekiBandyta.get_one_game_cost() << endl;
    cout << "2) Konstruktor przenoszący - nie można wykonać" << endl;
    cout << "3) Konstruktor 'konwertujący' - nie można wykonać" << endl;

    //Obserwacje: nie można wywołać konstuktora przenoszącego ani konwertującego. Możemy podać tylko referencje do istniejących instancji. Zmiany w funkcji mają wpływ na instancję w funkcji main.

    cout << endl;

    cout << "FUNKCJA PRZEZ R" << endl;
    cout << "1) Konstruktora kopiujący - nie można wykonać" << endl;
    cout << "2) Konstruktor przenoszący - nie można wykonać" << endl;
    cout << "3) Konstruktor 'konwertujący' :" << endl;
    f_R( JednorekiBandyta(1) );

    //Obserwacje: Możemy wykonać tylko konstruktor "konwertujący".

    //ZADANIA ZWIĄZANE Z LOGGEREM

    //Nie można wywołać metody log bezpośrednio z klasy JednorekiBandyta
    //Jest to spowodane tym, że nie wpisaliśmy żadnego operator więc domyślnie został ustawiony "private".
    //Oznacza, że wszystkie metody Loggera stały się prywatne
    //jednorekiBandyta.log("napis");

    //dodając atrybut "debug" do Loggera nie skompiluje się nam program, ponieważ klasa JednorekiBandyta nie wywołuje tego konstruktora
    // musimy dodać wywołanie konstruktora Loggera w JendorekimBandycie

    //ZADANIA ZE STOPEREM

    for (int i = 0 ; i < 1000; i++){
        jednorekiBandyta.play_game();
    }
    jednorekiBandyta.showTotal();

    //Ryzyko dziedziczenia z kilku klas jest takie, że nazwy atrybutów i metod moga się powtarzać.
    // W Javie nie ma wielokrotnego dziedziczenia, można tam natomiast rozszerzać klasy

}