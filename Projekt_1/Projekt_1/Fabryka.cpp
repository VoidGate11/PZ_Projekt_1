#pragma once

#include "Element.cpp"

//Klasa która tworzy obiekty Element metod¹ fabryki
class Fabryka {
public:
    static Element* utworz(int wartosc) {
        return new Element(wartosc);
    }
};