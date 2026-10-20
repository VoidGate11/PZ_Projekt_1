#pragma once
/**
 * @brief Tworzy nowy Element listy.
 * @param wartosc Wartoœæ przechowywana w Elemencie.
 */
//Klasa która przechowóje wartoœci i jest wykorzystywana jako element listy
class Element {
public:
    int wartosc;
    Element* poprzedni;
    Element* nastepny;

    Element(int wartosc) : wartosc(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
};