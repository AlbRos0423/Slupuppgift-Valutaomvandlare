#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <map>

using namespace std;

int main() {
    setlocale(LC_ALL, "sv_SE");

    map <string, double> valutakurser;          //Skapar en map med en string som nyckel och en double som värde
    string valuta;
    double kurs;

    ifstream file("C:/Users/Gymnasiet/source/repos/Project1/Project1/valutakurser.txt");        //Öppnar filen

    if (!file) {
        cout << "Kunde inte öppna valutakurser.txt\n";
        return 0;
    }

    cout << "Ange hur många SEK du vill konvertera: \n";
    double sek;
    cin >> sek;

    while (file >> valuta >> kurs) {
        valutakurser[valuta] = kurs;    //Delar upp filen i nycklar och värden
    }

    cout << "\nNedanstående valutor kan koverteras från SEK med hjälp av detta program; \n";
    cout << "USD (Amerikanska dollar)\n" << "EUR (Euro)\n" << "GBP (Brittiska pund)\n" << "NOK (Norska kronor)\n";


    file.close();

    cout << "\nVälj en valuta att konvertera till genom att skriva dess kod (med versaler): ";
    string val;
    cin >> val;

    if (val == "USD" || val == "EUR" || val == "GBP" || val == "NOK") { //Kollar om ditt val stämmer överens med en valutakurs

        cout << "\nValutakursen för " << val << " är " << valutakurser[val] << " vilket gör att du har " << sek * valutakurser[val] << " " << val << " efter konverteringen\n"; //Tar reda på valutakursen och räknar ut ett nytt värde
    }
    else {
        cout << "\nDin angivna valuta kod förknippas inte med någon av de valbara valutakurserna. Vänligen testa igen.\n";
    }

    return 0;
}