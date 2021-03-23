#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char wybór;

class Pojazd
{
    string marka;
    string model;
    int rocznik;
    int pojemność;
    float przebieg;
    string skrzynia;

public:
    friend int main();
    friend vector <Pojazd> wczytaj_Auta();
    friend void zapisywanie(vector <Pojazd> Auta);
    friend void sortowanie(vector<Pojazd> Auta);
    Pojazd(bool autko)
    {
        cout << "Podaj marke pojazdu: ";
        cin >> marka;
        cout << "Podaj model pojazdu: ";
        cin >> model;
        cout << "Podaj rok produkcji pojazdu: ";
        cin >> rocznik;
        cout << "Podaj pojemnosc silnika (w cm^3): ";
        cin >> pojemność;
        cout << "Podaj przebieg pojazdu (km): "; 
        cin >> przebieg;
        cout << "Podaj typ skrzyni biegow (reczna/automatyczna): ";
        cin >> skrzynia;
    }
    void wypisz()
    {
        cout << marka << " ";
        cout << model << " ";
        cout << rocznik << " ";
        cout << pojemność << " ";
        cout << przebieg << " ";
        cout << skrzynia << " ";
        cout << endl;
    }
    Pojazd() {};
};
void zapisywanie(vector <Pojazd> Auta)
{
    ofstream plik;
    plik.open("katalog.txt");
    for (Pojazd pojazd : Auta)
    {
        plik << pojazd.marka << " ";
        plik << pojazd.model << " ";
        plik << pojazd.rocznik << " ";
        plik << pojazd.pojemność << " ";
        plik << pojazd.przebieg << " ";
        plik << pojazd.skrzynia;
        plik << endl;
    }
    plik.close();
}
void wypisywanie(vector <Pojazd> Auta)
{
    for (Pojazd Pojazd : Auta)
    {
        Pojazd.wypisz();
    }
}
vector <Pojazd> wczytaj_Auta()
{
    vector <Pojazd> Auta;
    Pojazd Pojazd{};
    ifstream plik;
    plik.open("katalog.txt");
    while (plik.peek() != EOF)
    {
        plik >> Pojazd.marka;
        plik >> Pojazd.model;
        plik >> Pojazd.rocznik;
        plik >> Pojazd.pojemność;
        plik >> Pojazd.przebieg;
        plik >> Pojazd.skrzynia;

        if (!plik.eof())
        {
            Auta.push_back(Pojazd);
        }
    }
    plik.close();
    return Auta;
}
void sortowanie (vector<Pojazd> Auta){
    sort(Auta.begin(), Auta.end(), [](const Pojazd& x, const Pojazd& y) {
        if (x.marka != y.marka)
            return x.marka < y.marka;
        else if (x.model != y.model)
            return x.model < y.model;
        else if (x.rocznik != y.rocznik)
            return x.rocznik < y.rocznik;
        else if (x.pojemność != y.pojemność)
            return x.pojemność < y.pojemność;
        else if (x.przebieg != y.przebieg)
            return x.przebieg < y.przebieg;
        else if (x.skrzynia != y.skrzynia)
            return x.skrzynia < y.skrzynia;
        });
    wypisywanie(Auta);
}

int main()
{
    vector <Pojazd> Auta;
    Auta = wczytaj_Auta();
    Pojazd car;
    while (wybór != 7)
    {
        cout << "-------------------BAZA DANYCH-------------------" << endl;
        cout << "|                Wybierz opcje:                 |" << endl;
        cout << "| 1.Wprowadz dane nowego pojazdu                |" << endl;
        cout << "| 2.Wyswietl liste pojazdow                     |"<< endl;
        cout << "| 3.Wyswietl pojazdy spelniajace wymagania      |" << endl;
        cout << "| 4.Wyswietl dane pojedynczego pojazdu          |" << endl;
        cout << "| 5.Posortuj pojazdy                            |" << endl;
        cout << "| 6.Wyjdz                                       |" << endl;
        cout << "-------------------------------------------------\n" << endl;

        cout << "Wybierz: ";
        cin >> wybór;
        system("cls");

        switch (wybór)
        {
        case '1':
        {
            cout << "Wprowadz pojazd do katalogu: " << endl;
            Pojazd wprowadzany_pojazd = Pojazd(true);
            Auta.push_back(wprowadzany_pojazd);
            zapisywanie(Auta);
            cout << "Zapisano pomyslnie";
        }
        break;

        case '2':
        {
            cout << "Lista pojazdow: " << endl;
            wypisywanie(Auta);
        }
        break;

        case '3':
        {
            int w;
            cout << "Wybierz rodzaj wymagania: " << endl;
            cout << "1. Wypisz dana Marke" << endl;
            cout << "2. Wypisz dany model" << endl;
            cout << "3. Wypisz pojazdy z danym rocznikiem badz wyzszym" << endl;
            cout << "4. Wypisz pojazd z dana pojemnoscia badz wyzsza" << endl;
            cout << "5. Wypisz pojazd z przbiegiem nizszym badz rownym " << endl;
            cout << "6. Wypisz wybrany rodzaj skrzyni" << endl;
            cout << "Ktora opcja: ";
            cin >> w;
            ifstream plik;
            plik.open("katalog.txt");
            switch (w)
            {
            case 1: {
                string mr;
                cout << "jaka marka mam byc wypisana: ";
                cin >> mr ;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    plik >> car.rocznik;
                    plik >> car.pojemność;
                    plik >> car.przebieg;
                    plik >> car.skrzynia;
                    if (car.marka == mr)
                    {
                        
                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            case 2: {string ml;
                cout << "jakiego modelu poszukujesz: ";
                cin >> ml;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    if (car.model == ml)
                    {
                        plik >> car.rocznik;
                        plik >> car.pojemność;
                        plik >> car.przebieg;
                        plik >> car.skrzynia;

                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            case 3: {
                int ro;
                cout << "Od jakiego roku maja byc podawane pojazdy: ";
                cin >> ro;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    plik >> car.rocznik;
                    plik >> car.pojemność;
                    plik >> car.przebieg;
                    plik >> car.skrzynia;
                    if (ro <= car.rocznik)
                    {
                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            case 4: {float po;
                cout << "od jakiej pojemnosci mam wypisac: ";
                cin >> po;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    plik >> car.rocznik;
                    plik >> car.pojemność;
                    plik >> car.przebieg;
                    plik >> car.skrzynia;
                    if (car.pojemność >= po)
                    {
                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            case 5: {int pr;
                cout << "jaki ma byc przebieg: ";
                cin >> pr;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    plik >> car.rocznik;
                    plik >> car.pojemność;
                    plik >> car.przebieg;
                    plik >> car.skrzynia;
                    if (car.przebieg <= pr)
                    {
                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            case 6: {string sk;
                cout << "jaka ma byc skrzynia biegow (reczna/automatyczna): ";
                cin >> sk;
                while (plik.peek() != EOF)
                {
                    plik >> car.marka;
                    plik >> car.model;
                    plik >> car.rocznik;
                    plik >> car.pojemność;
                    plik >> car.przebieg;
                    plik >> car.skrzynia;
                    if (sk == car.skrzynia)
                    {
                        if (!plik.eof())
                        {
                            car.wypisz();
                        }
                    }
                }
                plik.close(); }
                  break;
            }
        }
        break;

        case '4':
        {
            cout << "podaj numer samochodu jaki chcesz zobaczyc: ";
            int numer;
            char opcja;
            cin >> numer;
            if (numer > 0 && numer <= Auta.size()) 
            {
                Auta[numer - 1].wypisz();

                cout << "Czy chcesz usunac ten pojazd?" << endl << "tak-1" << endl << "nie-inny klawisz" << endl<<"Podaj opcje: ";
                cin >> opcja;
                if (opcja == '1')
                {
                    if (numer > 0 && numer <= Auta.size())
                        Auta.erase(Auta.begin() + (numer - 1));

                    zapisywanie(Auta);
                    cout << "Zapisano pomyslnie\n";
                }
            }
            else
                cout << "Dany pojazd nie istnieje!\n";

        }
        break;

        case '5':
        {
            sortowanie(Auta);            
        } 
        break;
           
        case '6':
        {
            exit(0);
        }
        break;
        default: cout << "Nie ma takiej opcji w menu!" << endl;
        }
        _getch();

        system("cls");
    }
}