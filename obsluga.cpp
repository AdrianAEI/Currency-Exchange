#include "obsluga.h"
#include "kantor.h"
using namespace std;

void Konto::start(Konto*& pokaz)
{
    cout << "========================================" << endl;
    cout << "Witaj w kantorze!" << endl;
    cout << "Czy chcesz zalogowac sie do panelu admina?" << endl;
    cout << "Wpisz 'TAK' lub 'NIE'" << endl;
    cout << "========================================" << endl;
    bool sprawdzenie = 1;
    string wybor;
    cin >> wybor;
    if (wybor == "tak"||wybor =="TAK" || wybor == "Tak")
    {
        Administrator admin;
        pokaz = &admin;

        int proby=1;
        while (sprawdzenie)
            if (pokaz->loguj() == true)
            {
                pokaz->PokazOpcje();
                sprawdzenie = 0;
            }
            else
            {
                if (proby < 3)
                {
                    cout << "Zle dane sprobuj jeszcze raz." << endl;
                    proby++;
                }
                else
                {
                    cout << "Zbyt wiele razy wprowadzono bledne dane." << endl;
                    cout << "Program zostanie zamkniety." << endl;
                    sprawdzenie = 0;
                }


            }


    }
    else if ((wybor == "nie" || wybor == "NIE" || wybor == "Nie"))
    {
        Uzytkownik uzytkownik;
        pokaz = &uzytkownik;
        if (pokaz->loguj() == true)
        {
            pokaz->PokazOpcje();
        }
        else
        {
            cout << "Blad systemu." << endl;
        }
    }
    else
    {
        cout << "Bledny wybor." <<  endl;
        cout << "Program zostanie zamkniety." << endl;
    }
}
bool Uzytkownik::loguj()
{
    string login;
    cout << "Podaj login: " << endl;;
    cin >> login;
    return true;
}
bool Administrator::loguj()
{
    string login, haslo;
    cout << "========================================" << endl;
    cout << "Podaj login: " << endl;;
    cin >> login;
    cout << "Podaj haslo: " << endl;
    cin >> haslo;
    if ((login == "admin") && (haslo == "haslo"))
    {
        return true;
    }
    return false;
}
void Uzytkownik::PokazOpcje()
{
    Kantor waluty;
    waluty.wpisz_kursy();
    waluty.wpisz_ilosci();
    int wybor = {};
    cout << "========================================" << endl;
    cout << "Witaj w Kantorze!" << endl;
    cout << "Zostal otworzony panel dla uzytkownika." << endl;
    while (wybor != 5)
    {
        cout << "Wybierz opcje:" << endl;
        cout << "1. Kup walute." << endl;
        cout << "2. Sprzedaj walute." << endl;
        cout << "3. Sprawdz kursy." << endl;
        cout << "4. Sprawdz magazyn." << endl;
        cout << "5.Wyjdz" << endl;
        cin >> wybor;
        if (!cin.fail())
        {
            switch (wybor)
            {
            case 1:
                cout << "========================================" << endl;
                waluty.sprzedaz();
                cout << "========================================" << endl;
                break;
            case 2:
                cout << "========================================" << endl;
                waluty.kupno();
                cout << "========================================" << endl;
                break;
            case 3:
                cout << "========================================" << endl;
                waluty.wyswietl_waluty();
                cout << "========================================" << endl;
                break;
            case 4:
                cout << "========================================" << endl;
                waluty.wyswietl_magazyn();
                cout << "========================================" << endl;
                break;
            case 5:
                cout << "========================================" << endl;
                cout << "Dziekujemy i zapraszamy ponownie!" << endl;
                break;
            default:
                cout << "Bledny wybor" << endl;
                cout << "Sprobuj jeszcze raz" << endl;
                break;
            }
        }
        else
        {
            cout << "Wprowadzona wartosc nie jest liczba." << endl;
            cout << "Program zostanie zamkniety." << endl;
            wybor = 5;
        }
        
    }
}
void Administrator::PokazOpcje()
{
    Kantor waluty;
    waluty.wpisz_kursy();
    waluty.wpisz_ilosci();
    int  wybor = {};
    cout << "Witaj w Kantorze!" << endl;
    cout << "Masz dostep do panelu admina." << endl;
    while (wybor != 9)
    {
        cout << "Wybierz opcje:" << endl;
        cout << "1. Kup walute." << endl;
        cout << "2. Sprzedaj walute." << endl;
        cout << "3. Sprawdz kursy." << endl;
        cout << "4. Sprawdz magazyn." << endl;
        cout << "5. Zmien kursy walut" << endl;
        cout << "6. Dodaj nowa walute" << endl;
        cout << "7. Zwieksz ilosc waluty w magazynie" << endl;
        cout << "8. Sprawdz ile kantor zarobil." << endl;
        cout << "9. Wyjdz" << endl;
        cin >> wybor;
        if (!cin.fail())
        {
            switch (wybor)
            {
            case 1:
                cout << "========================================" << endl;
                waluty.sprzedaz();
                cout << "========================================" << endl;
                break;
            case 2:
                cout << "========================================" << endl;
                waluty.kupno();
                cout << "========================================" << endl;
                break;
            case 3:
                cout << "========================================" << endl;
                waluty.wyswietl_waluty();
                cout << "========================================" << endl;
                break;
            case 4:
                cout << "========================================" << endl;
                waluty.wyswietl_magazyn();
                cout << "========================================" << endl;
                break;
            case 5:
                cout << "========================================" << endl;
                waluty.zmiana_kursu();
                cout << "========================================" << endl;
                break;
            case 6:
                cout << "========================================" << endl;
                waluty.dodaj_walute();
                cout << "========================================" << endl;
                break;
            case 7:
                cout << "========================================" << endl;
                waluty.uzupelnij_magazyn();
                cout << "========================================" << endl;
                break;
            case 8:
                cout << "========================================" << endl;
                waluty.ile_zarobil();
                cout << "========================================" << endl;
                break;
            case 9:
                cout << "========================================" << endl;
                waluty.ile_zarobil();
                cout << "Skonczyles sesje " << endl;
                cout << endl;
                break;
            default:
                cout << "Bledny wybor" << endl;
                cout << "Sprobuj jeszcze raz" << endl;
                break;
            }
        }
        else
        {
            cout << "Wprowadzona wartosc nie jest liczba." << endl;
            cout << "Program zostanie zamkniety." << endl;
            wybor = 9;

        }
       
    }
}