#include"kantor.h"
#include"obsluga.h"
using namespace std;

void Kantor::kupno()
{
    {
        string szukaj1;
        string szukaj2;
        double ilosc;
        wyswietl_waluty();
        cout << "Podaj jaka walute chcesz sprzedac:" << endl;
        cin >> szukaj1;
        cout << "Podaj jaka walute chcesz otrzymac:" << endl;
        cin >> szukaj2;
        cout << "Podaj ilosc waluty ktora chcesz wymienic:" << endl;
        cin >> ilosc;   
        zmien_literki(szukaj1);
        zmien_literki(szukaj2);
       
        if ((waluta.find(szukaj1) != waluta.end()) && (waluta.find(szukaj2) != waluta.end()))
        {
            double temp = ilosc * (waluta[szukaj1].first / waluta[szukaj2].first);
            if (czy_mozliwa(szukaj2, temp))
            {
                edytuj(szukaj1, ilosc);
                cout << endl << "Ilosc otrzymanej waluty: " <<100*round( ilosc *(waluta[szukaj1].first / waluta[szukaj2].first))/100 << endl;
                zarobek.push_back(ilosc * (waluta[szukaj2].second - waluta[szukaj2].first));
                zapisz_zmiany();
            }
            else
            {
                cout << "Aktualnie nie posiadamy wystarczajacej ilosci " << szukaj2 << " w kantorze." << endl;
            }
        }
        else
        {
            cout << "Nasz kantor nie obsluguje takiej waluty." << endl;
        }
    }
}
void Kantor::sprzedaz()
{
    string szukaj;
    double ilosc;
    wyswietl_waluty();
    cout << "Podaj jaka walute chcesz kupic:" << endl;
    cin >> szukaj;
    cout << "Podaj ilosc waluty:" << endl;
    cin >> ilosc;
    zmien_literki(szukaj);
    if (waluta.find(szukaj) != waluta.end())
    {
        if (czy_mozliwa(szukaj, ilosc))
        {
            double temp = ilosc * waluta[szukaj].second;
            edytuj("zlotowka", temp);
            cout << "Do wykonania zakupu potrzebujesz " << 100*round(ilosc * waluta[szukaj].second)/100 << "zlotych" << endl;
            zarobek.push_back(ilosc * (waluta[szukaj].second - waluta[szukaj].first));
            zapisz_zmiany();
        }
        else
        {
            cout << "Aktualnie nie posiadamy tyle " << szukaj << " w kantorze" << endl;
        }
    }
    else
    {
        cout << "Nie posiadamy tej waluty w kantorze." << endl;
    }
}
void Kantor::ile_zarobil()
{
    double calkowity_zarobek = 0;
    if (zarobek.size() != 0)
    {
        for (auto it = begin(zarobek); it != end(zarobek); ++it) {
            calkowity_zarobek += *it;
        }
        cout << endl << "W biezacej sesji kantor zarobil: " << 100*round(calkowity_zarobek)/100 <<" zloty"<< endl;
    }
    else
    {
        cout << endl << "W biezacej sesji nie wykonano zadnej operacji wymiany." << endl;
    }


}
void Kantor::wpisz_kursy()
{
    fstream odczyt;
    odczyt.open("waluty.txt");
    if (!odczyt.good())
    {
        cout << "plik tekstowy nie zostal odnaleziony " << endl;
    }

    else
    {
        string nazwa;
        double wartosc1;
        double wartosc2;
        while (!odczyt.eof())
        {
            odczyt >> nazwa;
            odczyt >> wartosc1;
            odczyt >> wartosc2;
            waluta.insert({ nazwa, make_pair(wartosc1, wartosc2) });
        }

    }


}
void Kantor::wpisz_ilosci() {
    {
        fstream odczyt;
        odczyt.open("magazyn.txt");
        if (!odczyt.good())
        {
            cout << "plik tekstowy nie zostal odnaleziony " << endl;
        }

        else
        {
            string nazwa;
            double ilosc;
            while (!odczyt.eof())
            {
                odczyt >> nazwa;
                odczyt >> ilosc;
                magazyn.insert({ nazwa, ilosc });
            }

        }


    }
}
void Kantor::wyswietl_magazyn()
{

    cout << "Waluta:        " << "Ilosc w magazynie:    " << endl;
    map<string, double>::iterator podroznik;
    for (podroznik = magazyn.begin(); podroznik != magazyn.end(); ++podroznik)
    {
        cout << left << setw(20) << podroznik->first << " " << podroznik->second << endl;
    }

}

void Kantor::wyswietl_waluty()

{
    cout << "Waluta:        " << "Cena Kupna:     " << "Cena sprzedazy: " << endl << endl;
    map<string, pair<double, double>>::iterator podroznik;
    for (podroznik = waluta.begin(); podroznik != waluta.end(); ++podroznik)
    {
       
            cout <<left<< setw(20) << podroznik->first << setw(20) << podroznik->second.first << setw(20) << podroznik->second.second << endl;
               
    }
}
void Kantor::zmiana_kursu()
{
    string nazwa;
    
    cout << "Podaj nazwe waluty, ktorej kurs chcesz zmienic: " << endl;
    cin >> nazwa;
    zmien_literki(nazwa);
    if (waluta.find(nazwa) != waluta.end())
    {
        double cena1, cena2;
        cout << "Podaj nowa cene kupna:" << endl;
        cin >> cena1;

        cout << "Podaj nowa cene sprzedazy:" << endl;
        cin >> cena2;

        waluta.at(nazwa) = { cena1,cena2 };
        zapisz_zmiany();

    }
    else
        cout << "Nie znaleziono tej waluty." << endl;
}
void Kantor::dodaj_walute()
{
    string nazwa;
   
    cout << "Podaj nazwe waluty, ktora chcesz dodac: " << endl;
    cin >> nazwa;
    zmien_literki(nazwa);
    if (waluta.find(nazwa) != waluta.end())
    {
        cout << "Ta waluta jest juz w kantorze." << endl;
    }
    else
    {
        double cena1, cena2;
        double ilosc;
        cout << "Podaj cene kupna tej waluty: " << endl;
        cin >> cena1;
        cout << "Podaj cene sprzedazy tej waluty: " << endl;
        cin >> cena2;
        cout << "Podaj ilosc tej waluty: " << endl;
        cin >> ilosc;
        waluta.insert({ nazwa,make_pair(cena1,cena2) });
        magazyn.insert({ nazwa,ilosc });
        zapisz_zmiany();
    }
}
void Kantor::zmien_literki(string& nazwa)
{

    transform(nazwa.begin(), nazwa.end(), nazwa.begin(), ::tolower);

}
void Kantor::zapisz_zmiany()
{
    fstream odczyt1, odczyt2;
    odczyt1.open("magazyn.txt");
    if (!odczyt1.good())
    {
        cout << "plik tekstowy nie zostal odnaleziony " << endl;
    }

    else
    {
        for (auto it = magazyn.begin(); it != magazyn.end(); ++it)
        {
            odczyt1 << it->first << " " << it->second << endl;
        }
    }
    odczyt2.open("waluty.txt");
    if (!odczyt2.good())
    {
        cout << "plik tekstowy nie zostal odnaleziony " << endl;
    }

    else
    {
        for (auto it = waluta.begin(); it != waluta.end(); ++it)
        {
            odczyt2 << it->first << " " << it->second.first << " " << it->second.second << endl;
        }
    }
}
bool Kantor::czy_mozliwa(string nazwa, double& ilosc)
{


    if (magazyn.at(nazwa) >= ilosc)
    {
        magazyn.at(nazwa) -= ilosc;
        return true;

    }
    else
    {
        return false;
    }

}
void Kantor::edytuj(string nazwa, double& ilosc)
{
    magazyn.at(nazwa) += ilosc;
}
void Kantor::uzupelnij_magazyn()
{
    string nazwa;
    double dodatkowa_ilosc;
    cout << "Aktualny stan magazynu:" << endl;
    wyswietl_magazyn();
    cout << endl;
    cout << "Podaj nazwe waluty, ktorej ilosc chcesz uzupelnic: " << endl;
    cin >> nazwa;
    zmien_literki(nazwa);
    if (magazyn.find(nazwa) != magazyn.end())
    {
        cout << "Podaj ilosc ktora chcesz dodac do aktualnego stanu magazynu:" << endl;
        cin >> dodatkowa_ilosc;
        magazyn.at(nazwa) += dodatkowa_ilosc;
        zapisz_zmiany();

    }
    else
        cout << "Nie znaleziono tej waluty." << endl;
}