/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Malinka
 *
 * Created on 6. November 2016, 12:10
 */

#include <cstdlib>
#include "myarray.hpp"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char select = 'x';
    int eingabe = 0;
    int counter = 0;
    myArray<int, 10> stellplaetze{};
    myArray<string, 10> dauerparker{};
    stellplaetze.fill(stellplaetze, 1);
    
    do {
        cout << "\t(e) Parkplatz belegen" << endl;
        cout << "\t(a) Dauerparkplatz eintragen" << endl;
        cout << "\t(l) Alle belegten Parkplätze ausgeben" << endl;
        cout << "\t(x) Beenden" << endl;
        cout << "Ihre Eingabe:" << endl;
        cin >> select;

        switch (select) {
            case 'e':
                for(int i = 0; i<10; ++i){
                    if (stellplaetze.at(i) == 1){
                        counter++;}
                }
                if (counter!=10){
                    stellplaetze.printAll(stellplaetze);
                    cout << "Welchen Platz möchte Sie belegen? Es können nur Parkplätze belegt werden, welche eine 0 besitzen!" << endl;
                }else{
                    cout << "Alle Parkplätze sind belegt!" << endl;
                    counter = 0;
                    break;
                }
                cin >> eingabe;
                
                if(eingabe<0 || eingabe>10){
                    if(stellplaetze.at(eingabe) == 1){
                        stellplaetze.fillexplicit(stellplaetze, 0, eingabe);
                    }
                }
                counter = 0;
                break;
            case 'a':
                cin >> eingabe;
                cout << "Stellplatz " << eingabe << ": " << stellplaetze.at(eingabe) << endl;
                break;
            case 'l':
                break;
            case 'x':
                break;
        }

    } while (select != 'x');
    
    return 0;
}

