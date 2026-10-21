#pragma once

#include "Element.h"

/**
 * @brief Klasa tworz¹ca obiekty Element
 * z wykorzystaniem wzorca projektowego Factory.
 */
class Fabryka {
public:
    /**
     * @brief Tworzy nowy Element za pomoc¹ operatora new.
     * @param wartosc Wartoœæ przechowywana w elemencie.
     * @return WskaŸnik na utworzony element.
     */
    static Element* utworz(int wartosc);
};