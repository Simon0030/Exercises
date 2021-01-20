#include "Samochod.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct cmp{
    bool operator() (const Samochod &a, const Samochod &b)const{
        return a.odczytaj_pojemnosc_baku() < b.
        odczytaj_pojemnosc_baku();
    }
};

using namespace std;

int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
   /*... if(s1){
        cout << "audi" << endl;
    }
    if(!s1){
        cout << "!audi" << endl;
    }
    if(s2){
        cout << "bmw" << endl;
    }
    if(!s2){
        cout << "!bmw" << endl;
    }
    if(s3){
        cout << " " << endl;
    }
    if(!s3){
        cout << "!" << endl;
    }
    */
    vector<Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<endl;
    }

    set<Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it=s.begin(); it!=s.end(); ++it){
        cout<<*it<<endl;
    }
    return 0;
}
