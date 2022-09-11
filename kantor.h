#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <windows.h>

using namespace std;
class Kantor {
private:
    map<string, pair<double, double>> waluta;
    map<string, double> magazyn;
    vector <double> zarobek;
public:
    void kupno();

    void sprzedaz();

    void ile_zarobil();

    void wpisz_kursy();

    void wpisz_ilosci();

    void wyswietl_magazyn();

    void uzupelnij_magazyn();

    void wyswietl_waluty();

    void zmiana_kursu();

    void dodaj_walute();

    void zapisz_zmiany();
     
    void zmien_literki(string& nazwa);

    bool czy_mozliwa(string nazwa, double& ilosc);

    void edytuj(string nazwa, double& ilosc);
};
