#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <windows.h>
class Konto
{
public:
    void start(Konto*& pokaz);

    virtual bool loguj() = 0;

    virtual void PokazOpcje() = 0;
};

class Uzytkownik :public Konto
{
public:

    bool loguj();

    void PokazOpcje();
};

class Administrator :public Konto
{
public:

    bool loguj();

    void PokazOpcje();
};
