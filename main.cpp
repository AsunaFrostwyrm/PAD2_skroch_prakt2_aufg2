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
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char select = 'x';
    int eingabe = 0;
    int counter = 0;
    int dauerparkercounter = 0;
    string kennzeichen = "";
    string yesno = "";
    myArray<int, 10> stellplaetze{};
    myArray<string, 10> dauerparker{};
    stellplaetze.fill(stellplaetze, eingabe);
    dauerparker.fill(dauerparker, kennzeichen);

    do {
        cout << "\t(e) Parkplatz belegen" << endl;
        cout << "\t(a) Dauerparkplatz eintragen" << endl;
        cout << "\t(l) Alle belegten Parkplätze ausgeben" << endl;
        cout << "\t(o) Einen Parkplatz freigeben" << endl;
        cout << "\t(p) Alle Parkplätze freigeben" << endl;
        cout << "\t(x) Beenden" << endl;
        cout << "Ihre Eingabe:" << endl;
        cin >> select;

        switch (select) {
            case 'e':
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
                        dauerparkercounter++;
                    }
                }
                if (counter != 10) {
                    cout << "Folgende Parkplätze können noch belegt werden:" << endl;
                    for (int i = 0; i < 10; ++i) {
                        if (stellplaetze.at(i) == 0) {
                            cout << "Parkplatz Nummer " << i + 1 << endl;
                        }
                    }
                    cout << "Welchen Parkplatz möchte Sie belegen?" << endl;
                } else {
                    cout << "Alle Parkplätze sind belegt!" << endl;
                    counter = 0;
                    dauerparkercounter = 0;
                    break;
                }
                cin >> eingabe;
                eingabe = eingabe - 1;

                if (eingabe >= 0 && eingabe <= 10) {
                    if (stellplaetze.at(eingabe) == 0) {
                        stellplaetze.fillexplicit(stellplaetze, 1, eingabe);
                        cout << "Parkplatz Nummer " << eingabe + 1 << " wurde nun belegt!" << endl;
                    } else {
                        cout << "Parkplatz Nummer " << eingabe + 1 << " ist bereits belegt!" << endl;
                    }
                } else {
                    cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                }
                counter = 0;
                dauerparkercounter = 0;
                break;
            case 'a':
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
                        dauerparkercounter++;
                    }
                }
                if (counter != 10) {
                    if (dauerparkercounter != 3) {
                        cout << "Folgende Parkplätze können noch als Dauerparkplätze belegt werden:" << endl;
                        for (int i = 0; i < 10; ++i) {
                            if (stellplaetze.at(i) == 0) {
                                cout << "Parkplatz Nummer " << i + 1 << endl;
                            }
                        }
                        cout << "Welchen Parkplatz möchten Sie als Dauerparkplatz festlegen?" << endl;
                        cin >> eingabe;
                        eingabe = eingabe - 1;
                        if (eingabe >= 0 && eingabe <= 10) {
                            if (stellplaetze.at(eingabe) == 0) {
                                cout << "Um diesen Parkplatz belegen zu können müssen Sie das Kennzeichen angeben (Format: XX-XX-XXXX)" << endl;
                                cin >> kennzeichen;
                                stellplaetze.fillexplicit(stellplaetze, 2, eingabe);
                                dauerparker.fillexplicit(dauerparker, kennzeichen, eingabe);
                                cout << "Parkplatz Nummer " << eingabe + 1 << " wurde nun mit dem Kennzeichen " << kennzeichen << " belegt!" << endl;
                            } else {
                                cout << "Parkplatz Nummer " << eingabe + 1 << " ist bereits belegt!" << endl;
                            }
                        } else {
                            cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                        }
                    } else {
                        cout << "Es wurde bereits die maximale Anzahl an Dauerparkern erreicht! (3)" << endl;
                        counter = 0;
                        dauerparkercounter = 0;
                        break;
                    }
                } else {
                    cout << "Alle Parkplätze sind bereits belegt!" << endl;
                    counter = 0;
                    dauerparkercounter = 0;
                    kennzeichen = "";
                    break;
                }
                counter = 0;
                dauerparkercounter = 0;
                kennzeichen = "";

                break;
            case 'l':
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 0) {
                    } else if (stellplaetze.at(i) == 1) {
                        cout << "Parkplatz Nummer " << i + 1 << " ist als normaler Parkplatz belegt!" << endl;
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
                        cout << "Parkplatz Nummer " << i + 1 << " ist als Dauerparkplatz mit dem Kennzeichen " << dauerparker.at(i) << " belegt!" << endl;
                        counter++;
                    }
                }
                if(counter == 0){
                    cout << "Es sind derzeit keine Parkplätze belegt!" << endl;
                }
                counter = 0;
                break;
            case 'o':
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    }
                }
                if (counter != 0) {
                    cout << "Welchen Parkplatz möchten Sie freigeben?" << endl;
                    for (int i = 0; i < 10; ++i) {
                        if (stellplaetze.at(i) == 0) {
                        } else if (stellplaetze.at(i) == 1) {
                            cout << "Parkplatz Nummer " << i + 1 << ": Normaler Parker" << endl;
                        } else if (stellplaetze.at(i) == 2) {
                            cout << "Parkplatz Nummer " << i + 1 << ": Dauerparker\tKennzeichen:" << dauerparker.at(i) << endl;
                        }
                    }
                    cin >> eingabe;
                    eingabe = eingabe - 1;
                    if (eingabe >= 0 && eingabe <= 10) {
                        if(stellplaetze.at(eingabe) == 2){
                            cout << "Parkplatz Nummer " << eingabe+1 << " ist als Dauerparkplatz angegeben,\nmöchten Sie den Parkplatz trotzdem freigeben? (yes/no)" << endl;
                            cin >> yesno;
                            if(yesno == "yes"){
                                stellplaetze.fillexplicit(stellplaetze, 0, eingabe);
                                dauerparker.fillexplicit(dauerparker, kennzeichen, eingabe);
                                cout << "Parkplatz Nummer " << eingabe+1 << " wurde nun freigegeben!" << endl;
                            }else if(yesno == "no"){
                                cout << "Freigabe des Parkplatzes wurde abgebrochen!" << endl;
                                counter = 0;
                                break;
                            }else{
                                cout << "Ihre Eingabe entsprach nicht den Optionen 'yes' oder 'no', die Freigabe des Parkplatzes wurde abgebrochen!" << endl;
                                counter = 0;
                                break;
                            }
                        }else{
                            stellplaetze.fillexplicit(stellplaetze, 0, eingabe);
                            cout << "Parkplatz Nummer " << eingabe+1 << " wurde nun freigegeben!" << endl;
                        }
                    } else {
                        cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                    }
                } else {
                    cout << "Es ist noch kein Parkplatz belegt!" << endl;
                }
                counter = 0;
                break;
            case 'p':
                cout << "Möchten Sie wirklich alle Parkplätze freigeben?! Alle Dauerparker und normalen Parker werden gelöscht! (yes/no)" << endl;
                cin >> yesno;
                if(yesno == "yes"){
                    stellplaetze.fill(stellplaetze, 0);
                    dauerparker.fill(dauerparker, kennzeichen);
                    cout << "Alle Parkplätze wurden nun freigegeben!" << endl;
                }else if(yesno == "no"){
                    cout << "Die Freigabe aller Parkplätze wurde abgebrochen!" << endl;
                    break;
                }else{
                    cout << "Ihre Eingabe entsprach nicht den Optionen 'yes' oder 'no', die Freigabe aller Parkplätze wurde abgebrochen!" << endl;
                    break;
                }
                    
                break;
            case 'x':
                stellplaetze.~myArray();
                dauerparker.~myArray();
                break;
        }

    } while (select != 'x');

    return 0;
}

