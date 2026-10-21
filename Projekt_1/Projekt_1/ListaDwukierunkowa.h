#pragma once

#include "Element.h"
#include "Iterator.h"

/**
 * @brief Klasa implementuj¹ca listê dwukierunkow¹.
 */
class ListaDwukierunkowa {
private:
    Element* glowa;
    Element* ogon;
    int rozmiar;
    Iterator iterator;

    /**
     * @brief Sprawdza poprawnoœæ indeksu dodawania.
     * @param indeks Indeks wstawienia elementu.
     */
    void sprawdzIndeksDodawania(int indeks) const;

    /**
     * @brief Sprawdza poprawnoœæ indeksu usuwania.
     * @param indeks Indeks usuwanego elementu.
     */
    void sprawdzIndeksUsuwania(int indeks) const;

public:
    /**
     * @brief Tworzy pust¹ listê dwukierunkow¹.
     */
    ListaDwukierunkowa();

    /**
     * @brief Zabrania kopiowania listy.
     */
    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;

    /**
     * @brief Zabrania przypisywania list.
     */
    ListaDwukierunkowa& operator=(const ListaDwukierunkowa&) = delete;

    /**
     * @brief Niszczy listê i zwalnia pamiêæ.
     */
    ~ListaDwukierunkowa();

    /**
     * @brief Dodaje element na pocz¹tku listy.
     * @param wartosc Wartoœæ nowego elementu.
     */
    void dodajNaPoczatek(int wartosc);

    /**
     * @brief Dodaje element na koñcu listy.
     * @param wartosc Wartoœæ nowego elementu.
     */
    void dodajNaKoniec(int wartosc);

    /**
     * @brief Dodaje element pod wskazanym indeksem.
     * @param indeks Indeks wstawienia elementu.
     * @param wartosc Wartoœæ nowego elementu.
     */
    void dodajPodIndeks(int indeks, int wartosc);

    /**
     * @brief Usuwa pierwszy element listy.
     */
    void usunZPoczatku();

    /**
     * @brief Usuwa ostatni element listy.
     */
    void usunZKonca();

    /**
     * @brief Usuwa element o wskazanym indeksie.
     * @param indeks Indeks elementu do usuniêcia.
     */
    void usunPodIndeks(int indeks);

    /**
     * @brief Wyœwietla listê od pocz¹tku do koñca.
     */
    void wyswietl() const;

    /**
     * @brief Wyœwietla listê od koñca do pocz¹tku.
     */
    void wyswietlOdwrotnie() const;

    /**
     * @brief Wyœwietla element iteratora i przesuwa go do przodu.
     */
    void wyswietlNastepny();

    /**
     * @brief Wyœwietla element iteratora i przesuwa go do ty³u.
     */
    void wyswietlPoprzedni();

    /**
     * @brief Usuwa wszystkie elementy listy.
     */
    void wyczysc();
};