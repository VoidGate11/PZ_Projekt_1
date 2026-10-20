#include <iostream>

using namespace std;

//Klasa która przechowóje wartości i jest wykorzystywana jako element listy
class Element {
public:
    int wartosc;
    Element* poprzedni;
    Element* nastepny;

    Element(int wartosc): wartosc(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
};

//Klasa która tworzy obiekty Element metodą fabryki
class Fabryka {
public:
    static Element* utworz(int wartosc) {
        return new Element(wartosc);
    }
};

//Klasa która jest iteratorem
class Iterator {
private:
    Element* aktualny;

public:
    explicit Iterator(Element* start = nullptr)
        : aktualny(start) {
    }

    void ustaw(Element* wezel) {
        aktualny = wezel;
    }

    bool nastepny(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->nastepny;
        return true;
    }

    bool poprzedni(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->poprzedni;
        return true;
    }
};

class ListaDwukierunkowa {
private:
    Element* glowa;
    Element* ogon;
    int rozmiar;
    Iterator iterator;

    void sprawdzIndeksDodawania(int indeks) const {
        if (indeks < 0 || indeks > rozmiar) {
            throw std::out_of_range("Nieprawidlowy indeks dodawania.");
        }
    }

    void sprawdzIndeksUsuwania(int indeks) const {
        if (indeks < 0 || indeks >= rozmiar) {
            throw std::out_of_range("Nieprawidlowy indeks usuwania.");
        }
    }

public:
    ListaDwukierunkowa()
        : glowa(nullptr), ogon(nullptr), rozmiar(0), iterator(nullptr) {
    }

    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;
    ListaDwukierunkowa& operator=(const ListaDwukierunkowa&) = delete;

    ~ListaDwukierunkowa() {
        wyczysc();
    }

    int liczbaElementow() const {
        return rozmiar;
    }

    bool pusta() const {
        return rozmiar == 0;
    }

    void dodajNaPoczatek(int wartosc) {
        Element* nowy = Fabryka::utworz(wartosc);

        nowy->nastepny = glowa;

        if (glowa != nullptr) {
            glowa->poprzedni = nowy;
        }
        else {
            ogon = nowy;
        }

        glowa = nowy;
        ++rozmiar;
        iterator.ustaw(glowa);
    }

    void dodajNaKoniec(int wartosc) {
        Element* nowy = Fabryka::utworz(wartosc);

        nowy->poprzedni = ogon;

        if (ogon != nullptr) {
            ogon->nastepny = nowy;
        }
        else {
            glowa = nowy;
        }

        ogon = nowy;
        ++rozmiar;
        iterator.ustaw(glowa);
    }

    void dodajPodIndeks(int indeks, int wartosc) {
        sprawdzIndeksDodawania(indeks);

        if (indeks == 0) {
            dodajNaPoczatek(wartosc);
            return;
        }

        if (indeks == rozmiar) {
            dodajNaKoniec(wartosc);
            return;
        }

        Element* obecny = glowa;

        for (int i = 0; i < indeks; ++i) {
            obecny = obecny->nastepny;
        }

        Element* nowy = Fabryka::utworz(wartosc);

        nowy->poprzedni = obecny->poprzedni;
        nowy->nastepny = obecny;
        obecny->poprzedni->nastepny = nowy;
        obecny->poprzedni = nowy;

        ++rozmiar;
        iterator.ustaw(glowa);
    }

    void usunZPoczatku() {
        if (pusta()) {
            throw std::out_of_range("Lista jest pusta.");
        }

        Element* usuwany = glowa;
        glowa = glowa->nastepny;

        if (glowa != nullptr) {
            glowa->poprzedni = nullptr;
        }
        else {
            ogon = nullptr;
        }

        delete usuwany;
        --rozmiar;
        iterator.ustaw(glowa);
    }

    void usunZKonca() {
        if (pusta()) {
            throw std::out_of_range("Lista jest pusta.");
        }

        Element* usuwany = ogon;
        ogon = ogon->poprzedni;

        if (ogon != nullptr) {
            ogon->nastepny = nullptr;
        }
        else {
            glowa = nullptr;
        }

        delete usuwany;
        --rozmiar;
        iterator.ustaw(glowa);
    }

    void usunPodIndeks(int indeks) {
        sprawdzIndeksUsuwania(indeks);

        if (indeks == 0) {
            usunZPoczatku();
            return;
        }

        if (indeks == rozmiar - 1) {
            usunZKonca();
            return;
        }

        Element* usuwany = glowa;

        for (int i = 0; i < indeks; ++i) {
            usuwany = usuwany->nastepny;
        }

        usuwany->poprzedni->nastepny = usuwany->nastepny;
        usuwany->nastepny->poprzedni = usuwany->poprzedni;

        delete usuwany;
        --rozmiar;
        iterator.ustaw(glowa);
    }

    void wyswietl() const {
        Element* obecny = glowa;

        std::cout << "Lista: ";

        while (obecny != nullptr) {
            std::cout << obecny->wartosc << " ";
            obecny = obecny->nastepny;
        }

        std::cout << '\n';
    }

    void wyswietlOdwrotnie() const {
        Element* obecny = ogon;

        std::cout << "Lista odwrotnie: ";

        while (obecny != nullptr) {
            std::cout << obecny->wartosc << " ";
            obecny = obecny->poprzedni;
        }

        std::cout << '\n';
    }

    void wyswietlNastepny() {
        int wartosc;

        if (iterator.nastepny(wartosc)) {
            std::cout << "Nastepny element iteratora: "
                << wartosc << '\n';
        }
        else {
            std::cout << "Brak nastepnego elementu.\n";
        }
    }

    void wyswietlPoprzedni() {
        int wartosc;

        if (iterator.poprzedni(wartosc)) {
            std::cout << "Poprzedni element iteratora: "
                << wartosc << '\n';
        }
        else {
            std::cout << "Brak poprzedniego elementu.\n";
        }
    }

    void wyczysc() {
        Element* obecny = glowa;

        while (obecny != nullptr) {
            Element* nastepny = obecny->nastepny;
            delete obecny;
            obecny = nastepny;
        }

        glowa = nullptr;
        ogon = nullptr;
        rozmiar = 0;
        iterator.ustaw(nullptr);
    }
};

int main()
{
    ListaDwukierunkowa lista;

    std::cout << "=== DODAWANIE ELEMENTOW ===\n";

    lista.dodajNaPoczatek(20);
    lista.dodajNaPoczatek(10);
    lista.dodajNaKoniec(40);
    lista.dodajNaKoniec(50);
    lista.dodajPodIndeks(2, 30);

    // Oczekiwany wynik: 10 20 30 40 50
    lista.wyswietl();

    std::cout << "\n=== WYSWIETLANIE ODWROTNE ===\n";

    // Oczekiwany wynik: 50 40 30 20 10
    lista.wyswietlOdwrotnie();

    std::cout << "\n=== ITERATOR ===\n";

    // Iterator zaczyna od początku listy.
    lista.wyswietlNastepny();  // 10
    lista.wyswietlNastepny();  // 20
    lista.wyswietlNastepny();  // 30

    // Iterator znajduje się teraz na elemencie 40.
    lista.wyswietlPoprzedni(); // 40
    lista.wyswietlPoprzedni(); // 30

    std::cout << "\n=== USUWANIE ELEMENTOW ===\n";

    lista.usunZPoczatku();
    lista.wyswietl();          // 20 30 40 50

    lista.usunZKonca();
    lista.wyswietl();          // 20 30 40

    lista.usunPodIndeks(1);
    lista.wyswietl();          // 20 40

    std::cout << "\n=== INFORMACJE O LISCIE ===\n";

    std::cout << "Liczba elementow: "
        << lista.liczbaElementow() << '\n';

    std::cout << "Czy lista jest pusta? "
        << (lista.pusta() ? "Tak" : "Nie") << '\n';

    std::cout << "\n=== TEST NIEPRAWIDLOWEGO INDEKSU ===\n";

    try {
        lista.usunPodIndeks(10);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Blad: " << e.what() << '\n';
    }

    std::cout << "\n=== CZYSZCZENIE LISTY ===\n";

    lista.wyczysc();
    lista.wyswietl();

    std::cout << "Liczba elementow po czyszczeniu: "
        << lista.liczbaElementow() << '\n';

    std::cout << "Czy lista jest pusta? "
        << (lista.pusta() ? "Tak" : "Nie") << '\n';

    std::cout << "\n=== PONOWNY TEST PO CZYSZCZENIU ===\n";

    lista.dodajNaKoniec(100);
    lista.dodajNaKoniec(200);
    lista.wyswietl();

    lista.wyczysc();

    std::cout << "\nKoniec testow.\n";

    return 0;
}