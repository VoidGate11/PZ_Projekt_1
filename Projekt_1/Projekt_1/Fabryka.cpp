#include "Fabryka.h"

/**
 * @brief Tworzy nowy obiekt Element.
 * @param wartosc Wartoœæ przechowywana w elemencie.
 * @return WskaŸnik na nowo utworzony element.
 */
Element* Fabryka::utworz(int wartosc) {
    return new Element(wartosc);
}