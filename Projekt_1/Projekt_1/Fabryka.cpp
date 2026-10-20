#pragma once

#include "Element.cpp"
/**
 * @brief Tworzy nowy Element za pomoc¹ operatora new.
 * @param wartosc Wartoœæ przechowywana w Elemencie.
 * @return WskaŸnik na utworzony Element.
 */
//Klasa która tworzy obiekty Element metod¹ fabryki
class Fabryka {
public:
    static Element* utworz(int wartosc) {
        return new Element(wartosc);
    }
};