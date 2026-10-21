#include "Iterator.h"

/**
 * @brief Inicjalizuje iterator wskazuj¹cy na podany element.
 * @param start Pocz¹tkowy element iteratora.
 */
Iterator::Iterator(Element* start)
    : aktualny(start) {
}

/**
 * @brief Ustawia iterator na wskazanym elemencie.
 * @param wezel Element, na który ma wskazywaæ iterator.
 */
void Iterator::ustaw(Element* wezel) {
    aktualny = wezel;
}

/**
 * @brief Odczytuje wartoœæ bie¿¹cego elementu
 * i przesuwa iterator do przodu.
 * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
 * @return true, jeœli odczytano element, w przeciwnym razie false.
 */
bool Iterator::nastepny(int& wartosc) {
    if (aktualny == nullptr) {
        return false;
    }

    wartosc = aktualny->wartosc;
    aktualny = aktualny->nastepny;

    return true;
}

/**
 * @brief Odczytuje wartoœæ bie¿¹cego elementu
 * i przesuwa iterator do ty³u.
 * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
 * @return true, jeœli odczytano element, w przeciwnym razie false.
 */
bool Iterator::poprzedni(int& wartosc) {
    if (aktualny == nullptr) {
        return false;
    }

    wartosc = aktualny->wartosc;
    aktualny = aktualny->poprzedni;

    return true;
}