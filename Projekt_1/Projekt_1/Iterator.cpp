#pragma once

#include "Element.cpp"

//Klasa która jest iteratorem
class Iterator {
private:
    Element* aktualny;

public:
    explicit Iterator(Element* start = nullptr)
        : aktualny(start) {
    }

    void ustaw(Element* wezel) {
        aktualny = wezel;
    }

    bool nastepny(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->nastepny;
        return true;
    }

    bool poprzedni(int& wartosc) {
        if (aktualny == nullptr) {
            return false;
        }

        wartosc = aktualny->wartosc;
        aktualny = aktualny->poprzedni;
        return true;
    }
};