import pickle
class samochód:
    def __init__(self, marka , model,rocznik, pojemność, przebieg, skrzynia):
        self.marka = marka
        self.model = model
        self.rocznik = rocznik
        self.pojemność = pojemność
        self.przebieg = przebieg
        self.skrzynia = skrzynia
    def wypisz(self):
        txt = "Marka: {} Model: {} Rok produkcji: {} Pojemność: {} cm³ Przebieg: {}km Skrzynia Biegów: {}"
        print(txt.format(self.marka, self.model, self.rocznik, self.pojemność, self.przebieg, self.skrzynia))

def dodawanie():
    marka = input("podaj markę pojazdu: ", )
    model = input("podaj model pojazdu: ", )
    rocznik = input("podaj rok produkcji pojazdu: ", )
    pojemność = input("podaj pojemność pojazdu(w cm^3): ", )
    przebieg = input("podaj przebieg pojazdu(w Km): ", )
    skrzynia = input("podaj skrzynie biegów pojazdu(automatyczna/ręczna): ", )
    return samochód(marka, model, rocznik, pojemność, przebieg, skrzynia)

def zapisywanie(katalog):
    plik = open("katalog", "wb")
    pickle.dump(katalog, plik)
    plik.close()

def wczytywanie(katalog):
    try:
        plik = open("katalog", "rb")
        katalog = pickle.load(plik)
        plik.close()
        return katalog
    except IOError:
        return katalog

katalog = []
katalog = wczytywanie(katalog)
wybor = "0"
while True:
    print("-------------------BAZA DANYCH-------------------")
    print("|                Wybierz opcje:                 |")
    print("| 1.Wprowadź dane nowego pojazdu                |")
    print("| 2.Wyświetl liste pojazdów                     |")
    print("| 3.Wyświetl pojazdy spełniające wymagania      |")
    print("| 4.Wyświetl dane pojedynczego pojazdu          |")
    print("| 5.Posortuj pojazdy                            |")
    print("| 6.Wyjdź                                       |")
    print("-------------------------------------------------")
    wybor = input("Jaki wybór? ", )
    if wybor == "6":
        exit(0)
    elif wybor == "1":
        print("wprowadź dane pojazdu: ")
        katalog.append(dodawanie())
        zapisywanie(katalog)
        print()
    elif wybor == "2":
        print("Oto cały katalog: ")
        i = 0
        for  pojazd in katalog:
            pojazd.wypisz()
        print()
    elif wybor == "3":
        opcja = 1
        while int(opcja) >= 6 or int(opcja) <= 1:
            print("wybierz wymaganie jakie auta mają spełniać: ")
            print("1.wymień wszystkie pojazdy tej samej marki")
            print("2.wymień pojazdy z tym samym modelem")
            print("3.wymień pojazd z tym samym bądź młodszym rocznikiem")
            print("4.wymień pojazd z podaną pojemnością bądź większą")
            print("5.wymień pojazdy z podanym przebiegiem bądź niższym")
            print("6.wymień pojazdy z wybraną skrzynią biegów")
            print("7.wyjście")
            opcja = input("wybierz opcję: ", )
            i=0
            if int(opcja) == 1:
                x=input("jakiej marki poszukujesz: ", )
                while i != len(katalog):
                    if katalog[i].marka == x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 2:
                x = input("jakiego modelu poszukujesz: ", )
                while i != len(katalog):
                    if katalog[i].model == x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 3:
                x = input("od jakiego roczniku szukasz: ", )
                while i != len(katalog):
                    if katalog[i].rocznik >= x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 4:
                x = input("od jakiej pojemności poszukujesz: ", )
                while i != len(katalog):
                    if katalog[i].pojemność >= x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 5:
                x = input("do jakiego przebigu poszukujesz: ", )
                while i != len(katalog):
                    if katalog[i](samochód.przebieg) <= x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 6:
                x = input("jaką skrzynię poszukujesz: (automatyczna/ręczna)", )
                while i != len(katalog):
                    if katalog[i](samochód.skrzynia) == x:
                        katalog[i].wypisz()
                    i += 1
                print(" ")
            elif int(opcja) == 7:
                break
            else:
                print("Taki wybór nie istnieje!")
        print()
    elif wybor == "4":
        x = input("wybierz numer auta jaki mam się pojawić na ekranie: ", )
        x =int(x) - 1
        katalog[x].wypisz()
        print("czy chcesz usunąć ten pojazd? (t)")
        y=input()
        if y == "t":
            katalog.pop(x)
            zapisywanie(katalog)
        print()
    elif wybor == "5":
        print("sortowanie: ")
        katalog.sort(key=lambda x: x.marka,reverse=False)
        print()
    else:
        print("Nie istnieje taka opcja")
        print()
