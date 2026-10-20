#pragma once

#include <iostream>
#include "Element.cpp"
#include "Fabryka.cpp"
#include "Iterator.cpp"

//G³ówna klasa Listy dwukierunkowej
class ListaDwukierunkowa {
private:
    Element* glowa;
    Element* ogon;
    int rozmiar;
    Iterator iterator;
public:
    ListaDwukierunkowa()
        : glowa(nullptr), ogon(nullptr), rozmiar(0), iterator(nullptr) {
    }

    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;
    ListaDwukierunkowa& operator=(const ListaDwukierunkowa&) = delete;

    ~ListaDwukierunkowa() {
        wyczysc();
    }
    // Metoda ktora dodaje element na poczatek
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
    // Metoda ktora dodaje element na koniec
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
    // Metoda ktora dodaje element pod indeksem
    void dodajPodIndeks(int indeks, int wartosc) {

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
    // Metoda ktora usuwa element z poczatku
    void usunZPoczatku() {

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
    // Metoda ktora usuwa element z konca
    void usunZKonca() {

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
    // Metoda ktora usuwa element pod indeksem
    void usunPodIndeks(int indeks) {

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
    // Metoda ktora wyswietla liste
    void wyswietl() const {
        Element* obecny = glowa;

        std::cout << "Lista: ";

        while (obecny != nullptr) {
            std::cout << obecny->wartosc << " ";
            obecny = obecny->nastepny;
        }

        std::cout << '\n';
    }
    // Metoda ktora wyswietla liste odwrotnie
    void wyswietlOdwrotnie() const {
        Element* obecny = ogon;

        std::cout << "Lista odwrotnie: ";

        while (obecny != nullptr) {
            std::cout << obecny->wartosc << " ";
            obecny = obecny->poprzedni;
        }

        std::cout << '\n';
    }
    // Metoda ktora wyswietla nastepny element
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
    // Metoda ktora wyswietla poprzedni element
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
    // Metoda ktora czysci liste
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