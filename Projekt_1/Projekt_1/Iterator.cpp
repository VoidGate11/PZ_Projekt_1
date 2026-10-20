#pragma once

#include "Element.cpp"

//Klasa która jest iteratorem
class Iterator {
private:
    Element* aktualny;

public:
    /**
     * @brief Tworzy iterator wskazuj¹cy na podany Element.
     * @param start Pocz¹tkowy Element iteratora.
     */
    explicit Iterator(Element* start = nullptr)
        : aktualny(start) {
    }

    /**
     * @brief Ustawia iterator na wskazanym Elemencie.
     * @param wezel Element, na który ma wskazywaæ iterator.
     */
    void ustaw(Element* wezel) {
        aktualny = wezel;
    }

    /**
     * @brief Zwraca wartoœæ bie¿¹cego elementu i przesuwa iterator do przodu.
     * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
     * @return true, jeœli odczytano element, w przeciwnym razie false.
     */
    bool nastepny(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->nastepny;
        return true;
    }

    /**
     * @brief Zwraca wartoœæ bie¿¹cego elementu i przesuwa iterator do ty³u.
     * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
     * @return true, jeœli odczytano element, w przeciwnym razie false.
     */
    bool poprzedni(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->poprzedni;
        return true;
    }
};