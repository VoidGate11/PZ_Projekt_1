#pragma once

/**
 * @brief Klasa przechowuj¹ca wartoœci i pe³ni¹ca
 * funkcjê elementu listy dwukierunkowej.
 */
class Element {
public:
    int wartosc;
    Element* poprzedni;
    Element* nastepny;

    /**
     * @brief Tworzy nowy element listy.
     * @param wartosc Wartoœæ przechowywana w elemencie.
     */
    Element(int wartosc);
};