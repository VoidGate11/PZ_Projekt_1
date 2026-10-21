#include "ListaDwukierunkowa.h"
#include "Fabryka.h"

#include <iostream>
#include <stdexcept>

ListaDwukierunkowa::ListaDwukierunkowa()
    : glowa(nullptr), ogon(nullptr), rozmiar(0), iterator(nullptr) {
}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    wyczysc();
}

void ListaDwukierunkowa::sprawdzIndeksDodawania(int indeks) const {
    if (indeks < 0 || indeks > rozmiar) {
        throw std::out_of_range("Nieprawidlowy indeks dodawania.");
    }
}

void ListaDwukierunkowa::sprawdzIndeksUsuwania(int indeks) const {
    if (indeks < 0 || indeks >= rozmiar) {
        throw std::out_of_range("Nieprawidlowy indeks usuwania.");
    }
}

void ListaDwukierunkowa::dodajNaPoczatek(int wartosc) {
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

void ListaDwukierunkowa::dodajNaKoniec(int wartosc) {
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

void ListaDwukierunkowa::dodajPodIndeks(int indeks, int wartosc) {
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

void ListaDwukierunkowa::usunZPoczatku() {

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

void ListaDwukierunkowa::usunZKonca() {

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

void ListaDwukierunkowa::usunPodIndeks(int indeks) {
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

void ListaDwukierunkowa::wyswietl() const {
    Element* obecny = glowa;

    std::cout << "Lista: ";

    while (obecny != nullptr) {
        std::cout << obecny->wartosc << " ";
        obecny = obecny->nastepny;
    }

    std::cout << '\n';
}

void ListaDwukierunkowa::wyswietlOdwrotnie() const {
    Element* obecny = ogon;

    std::cout << "Lista odwrotnie: ";

    while (obecny != nullptr) {
        std::cout << obecny->wartosc << " ";
        obecny = obecny->poprzedni;
    }

    std::cout << '\n';
}

void ListaDwukierunkowa::wyswietlNastepny() {
    int wartosc;

    if (iterator.nastepny(wartosc)) {
        std::cout << "Nastepny element iteratora: "
            << wartosc << '\n';
    }
    else {
        std::cout << "Brak nastepnego elementu.\n";
    }
}

void ListaDwukierunkowa::wyswietlPoprzedni() {
    int wartosc;

    if (iterator.poprzedni(wartosc)) {
        std::cout << "Poprzedni element iteratora: "
            << wartosc << '\n';
    }
    else {
        std::cout << "Brak poprzedniego elementu.\n";
    }
}

void ListaDwukierunkowa::wyczysc() {
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