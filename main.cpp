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
            case 'e': //Eingabe eines normalen Parkplatzes
		//Schleife zur Ermittlung aller belegten Plaetze
                for (int i = 0; i < 10; ++i) { 
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
                        dauerparkercounter++;
                    }
		//Bedingung zum Abbruch wenn alle Plaetze belegt sind
                if (counter != 10) {
                    cout << "Folgende Parkplätze können noch belegt werden:" << endl;
		    //Schleife zur Ausgabe aller nicht belegten Plaetze
                    for (int i = 0; i < 10; ++i) {
                        if (stellplaetze.at(i) == 0) {
                            cout << "Parkplatz Nummer " << i + 1 << endl;
                        }
                    }
                    cout << "Welchen Parkplatz möchte Sie belegen?" << endl;
                } else {
		    //Abbruchausfuehrung wenn alle Plaetze belegt sind
                    cout << "Alle Parkplätze sind belegt!" << endl;
                    counter = 0;
                    dauerparkercounter = 0;
                    break;
                }
		//Eingabe des gewuenschten Parkplatzes
                cin >> eingabe;
                eingabe = eingabe - 1;
		//Ueberpruefung, ob ein verwertbarer Index eingegeben wurde
                if (eingabe >= 0 && eingabe <= 10) {
		    //Ueberpruefung, ob der gewaehlte Platz schon vergeben ist
                    if (stellplaetze.at(eingabe) == 0) {
                        stellplaetze.fillexplicit(stellplaetze, 1, eingabe);
                        cout << "Parkplatz Nummer " << eingabe + 1 << " wurde nun belegt!" << endl;
                    } else {
			//Abbruchausgabe
                        cout << "Parkplatz Nummer " << eingabe + 1 << " ist bereits belegt!" << endl;
                    }
                } else {
		    //Abbruchausgabe
                    cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                }
		//Zuruecksetzen der Counter
                counter = 0;
                dauerparkercounter = 0;
                break;
            case 'a': //Eingabe eines Dauerparkplatzes
		//Schleife zur Ermittlung aller belegten Plaetze
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
                        dauerparkercounter++;
                    }
                }
		//Bedingung zum Abbruch wenn alle Plaetze belegt sind
                if (counter != 10) {
		    //Bedingung zum Abbruch wenn bereits 3 Dauerparker belegt sind
                    if (dauerparkercounter != 3) {
                        cout << "Folgende Parkplätze können noch als Dauerparkplätze belegt werden:" << endl;
			//Schleife zur Ausgabe aller freien Parkplaetze
                        for (int i = 0; i < 10; ++i) {
                            if (stellplaetze.at(i) == 0) {
                                cout << "Parkplatz Nummer " << i + 1 << endl;
                            }
                        }
                        cout << "Welchen Parkplatz möchten Sie als Dauerparkplatz festlegen?" << endl;
			//Eingabe des gewuenschten Parkplatzes
                        cin >> eingabe;
                        eingabe = eingabe - 1;
			//Ueberpruefung, ob ein verwertbarer Index eingegeben wurde
                        if (eingabe >= 0 && eingabe <= 10) {
			    //Ueberpruefung, ob der gewaehlte Platz schon vergeben ist
                            if (stellplaetze.at(eingabe) == 0) {
                                cout << "Um diesen Parkplatz belegen zu können müssen Sie das Kennzeichen angeben (Format: XX-XX-XXXX)" << endl;
                                cin >> kennzeichen;
                                stellplaetze.fillexplicit(stellplaetze, 2, eingabe);
                                dauerparker.fillexplicit(dauerparker, kennzeichen, eingabe);
                                cout << "Parkplatz Nummer " << eingabe + 1 << " wurde nun mit dem Kennzeichen " << kennzeichen << " belegt!" << endl;
                            } else {
				//Abbruchausgabe
                                cout << "Parkplatz Nummer " << eingabe + 1 << " ist bereits belegt!" << endl;
                            }
                        } else {
			    //Abbruchausgabe
                            cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                        }
                    } else {
			//Abbruchausgabe
                        cout << "Es wurde bereits die maximale Anzahl an Dauerparkern erreicht! (3)" << endl;
			//Zuruecksetzen der Counter
                        counter = 0;
                        dauerparkercounter = 0;
                        break;
                    }
                } else {
		    //Abbruchausgabe
                    cout << "Alle Parkplätze sind bereits belegt!" << endl;
		    //Zuruecksetzen der Counter
                    counter = 0;
                    dauerparkercounter = 0;
                    kennzeichen = "";
                    break;
                }
		//Zuruecksetzen der Counter
                counter = 0;
                dauerparkercounter = 0;
                kennzeichen = "";

                break;
            case 'l': //Ausgabe aller belegten Parkplaetze
		//Hochzaehlen des Indexes
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 0) {
                    } else if (stellplaetze.at(i) == 1) {
			//Ausgabe fuer normalen Stellplatz
                        cout << "Parkplatz Nummer " << i + 1 << " ist als normaler Parkplatz belegt!" << endl;
                        counter++;
                    } else if (stellplaetze.at(i) == 2) {
			//Ausgabe fuer Dauerstellplatz
                        cout << "Parkplatz Nummer " << i + 1 << " ist als Dauerparkplatz mit dem Kennzeichen " << dauerparker.at(i) << " belegt!" << endl;
                        counter++;
                    }
                }
                if(counter == 0){
                    cout << "Es sind derzeit keine Parkplätze belegt!" << endl;
                }
		//Zuruecksetzen des Counters
                counter = 0;
                break;
            case 'o': //Platz freigeben mithilfe des Indexes
		//Zaehlen aller belegten Plaetze
                for (int i = 0; i < 10; ++i) {
                    if (stellplaetze.at(i) == 1) {
                        counter++;
                    }
                }
		//Abbruchbedingung wenn keine Parkplaetze belegt sind
                if (counter != 0) {
                    cout << "Welchen Parkplatz möchten Sie freigeben?" << endl;
                    for (int i = 0; i < 10; ++i) {
                        if (stellplaetze.at(i) == 0) { //Ausgabe aller belegten Parkplaetze 
                        } else if (stellplaetze.at(i) == 1) {
                            cout << "Parkplatz Nummer " << i + 1 << ": Normaler Parker" << endl;
                        } else if (stellplaetze.at(i) == 2) {
                            cout << "Parkplatz Nummer " << i + 1 << ": Dauerparker\tKennzeichen:" << dauerparker.at(i) << endl;
                        }
                    }
		    //Eingabe des gewuenschten Parkplatzes
                    cin >> eingabe;
                    eingabe = eingabe - 1;
		    //Ueberpruefung, ob ein verwertbarer Index eingegeben wurde
                    if (eingabe >= 0 && eingabe <= 10) {
                        if(stellplaetze.at(eingabe) == 2){ //Auswahlmoeglichkeit fuer Abbruch der Freigabe bei Dauerparkplatz
                            cout << "Parkplatz Nummer " << eingabe+1 << " ist als Dauerparkplatz angegeben,\nmöchten Sie den Parkplatz trotzdem freigeben? (yes/no)" << endl;
                            cin >> yesno;
                            if(yesno == "yes"){ //Freigabe des Parkplatzes
                                stellplaetze.fillexplicit(stellplaetze, 0, eingabe);
                                dauerparker.fillexplicit(dauerparker, kennzeichen, eingabe);
                                cout << "Parkplatz Nummer " << eingabe+1 << " wurde nun freigegeben!" << endl;
                            }else if(yesno == "no"){ //Abbruch der Freigabe des Parkplatzes
                                cout << "Freigabe des Parkplatzes wurde abgebrochen!" << endl;
                                counter = 0;
                                break;
                            }else{
				//Abbruch bei nicht korrekt eingegebener Auswahl
                                cout << "Ihre Eingabe entsprach nicht den Optionen 'yes' oder 'no', die Freigabe des Parkplatzes wurde abgebrochen!" << endl;
                                counter = 0;
                                break;
                            }
                        }else{ //Freigabe des Parkplatzes
                            stellplaetze.fillexplicit(stellplaetze, 0, eingabe);
                            cout << "Parkplatz Nummer " << eingabe+1 << " wurde nun freigegeben!" << endl;
                        }
                    } else { //Abbruch bei nicht verwertbaren Index
                        cout << "Sie müssen eine Nummer zwischen 0 und 10 wählen! Ihre Nummer: " << eingabe + 1 << endl;
                    }
                } else { //Abbruch wenn kein Parkplatz belegt ist
                    cout << "Es ist noch kein Parkplatz belegt!" << endl;
                }
		//Zuruecksetzen des Counters
                counter = 0;
                break;
            case 'p': //Freigabe aller Parkplaetze
		//Warnung fuer die Freigabe aller Parkplaetze
                cout << "Möchten Sie wirklich alle Parkplätze freigeben?! Alle Dauerparker und normalen Parker werden gelöscht! (yes/no)" << endl;
                cin >> yesno;
                if(yesno == "yes"){ //Freigabe aller Parkplaetze
                    stellplaetze.fill(stellplaetze, 0);
                    dauerparker.fill(dauerparker, kennzeichen);
                    cout << "Alle Parkplätze wurden nun freigegeben!" << endl;
                }else if(yesno == "no"){ //Abbruch bei nicht gewuenschter Freigabe
                    cout << "Die Freigabe aller Parkplätze wurde abgebrochen!" << endl;
                    break;
                }else{ //Abbruch bei nicht korrekt eingegebener Auswahl
                    cout << "Ihre Eingabe entsprach nicht den Optionen 'yes' oder 'no', die Freigabe aller Parkplätze wurde abgebrochen!" << endl;
                    break;
                }
                    
                break;
            case 'x': //Beenden
                stellplaetze.~myArray(); //Destruktoraufruf
                dauerparker.~myArray(); //Destruktoraufruf
                break;
        }

    } while (select != 'x'); //Beenden des Programms

    return 0;
}

