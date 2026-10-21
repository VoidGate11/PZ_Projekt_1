#pragma once

#include "Element.h"

/**
 * @brief Klasa realizuj¹ca wzorzec projektowy Iterator
 * dla listy dwukierunkowej.
 */
class Iterator {
private:
    Element* aktualny;

public:
    /**
     * @brief Tworzy iterator wskazuj¹cy na podany element.
     * @param start Pocz¹tkowy element iteratora.
     */
    explicit Iterator(Element* start = nullptr);

    /**
     * @brief Ustawia iterator na wskazanym elemencie.
     * @param wezel Element, na który ma wskazywaæ iterator.
     */
    void ustaw(Element* wezel);

    /**
     * @brief Odczytuje bie¿¹cy element i przesuwa iterator do przodu.
     * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
     * @return true, jeœli odczytano element, w przeciwnym razie false.
     */
    bool nastepny(int& wartosc);

    /**
     * @brief Odczytuje bie¿¹cy element i przesuwa iterator do ty³u.
     * @param wartosc Zmienna przechowuj¹ca odczytan¹ wartoœæ.
     * @return true, jeœli odczytano element, w przeciwnym razie false.
     */
    bool poprzedni(int& wartosc);
};
