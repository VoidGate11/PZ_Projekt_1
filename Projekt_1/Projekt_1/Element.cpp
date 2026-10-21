#include "Element.h"

/**
 * @brief Inicjalizuje nowy element listy.
 * @param wartosc Wartoœæ przechowywana w elemencie.
 */
Element::Element(int wartosc)
    : wartosc(wartosc),
    poprzedni(nullptr),
    nastepny(nullptr) {
}