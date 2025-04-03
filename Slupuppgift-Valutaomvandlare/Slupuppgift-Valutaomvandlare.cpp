#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <map>

using namespace std;

int main() {
    setlocale(LC_ALL, "sv_SE");

    map <string, double> valutakurser;          //Skapar en map med en string som nyckel och en double som v�rde
    string valuta;
    double kurs;

    ifstream file("C:/Users/Gymnasiet/source/repos/Project1/Project1/valutakurser.txt");        //�ppnar filen

    if (!file) {
        cout << "Kunde inte �ppna valutakurser.txt\n";
        return 0;
    }

    cout << "Ange hur m�nga SEK du vill konvertera: \n";
    double sek;
    cin >> sek;

    while (file >> valuta >> kurs) {
        valutakurser[valuta] = kurs;    //Delar upp filen i nycklar och v�rden
    }

    cout << "\nNedanst�ende valutor kan koverteras fr�n SEK med hj�lp av detta program; \n";
    cout << "USD (Amerikanska dollar)\n" << "EUR (Euro)\n" << "GBP (Brittiska pund)\n" << "NOK (Norska kronor)\n";


    file.close();

    cout << "\nV�lj en valuta att konvertera till genom att skriva dess kod (med versaler): ";
    string val;
    cin >> val;

    if (val == "USD" || val == "EUR" || val == "GBP" || val == "NOK") { //Kollar om ditt val st�mmer �verens med en valutakurs

        cout << "\nValutakursen f�r " << val << " �r " << valutakurser[val] << " vilket g�r att du har " << sek * valutakurser[val] << " " << val << " efter konverteringen\n"; //Tar reda p� valutakursen och r�knar ut ett nytt v�rde
    }
    else {
        cout << "\nDin angivna valuta kod f�rknippas inte med n�gon av de valbara valutakurserna. V�nligen testa igen.\n";
    }

    return 0;
}