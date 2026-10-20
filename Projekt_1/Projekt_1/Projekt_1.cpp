#include <iostream>
#include "ListaDwukierunkowa.cpp"

using namespace std;

int main()
{
    ListaDwukierunkowa lista;

    cout << "\n=== Stwozenie i wyswietlenie listy ===\n";

    cout << "Z poczatku: \n";
    lista.dodajNaPoczatek(20);
    lista.dodajNaPoczatek(10);
    lista.wyswietl();

    cout << "Z konca: \n";
    lista.dodajNaKoniec(40);
    lista.dodajNaKoniec(50);
    lista.wyswietl();

    cout << "Z indeksu: \n";
    lista.dodajPodIndeks(2, 30);

    lista.wyswietl();

    cout << "\n=== Wyswietlenie odwrotne ===\n";

    lista.wyswietlOdwrotnie();

    cout << "\n=== Iterator ===\n";

    lista.wyswietlNastepny();
    lista.wyswietlNastepny();
    lista.wyswietlNastepny();

    lista.wyswietlPoprzedni();
    lista.wyswietlPoprzedni();

    cout << "\n=== Usuwanie elementow ===\n";

    cout << "Z poczatku: \n";
    lista.usunZPoczatku();
    lista.wyswietl();

    cout << "Z konca: \n";
    lista.usunZKonca();
    lista.wyswietl();

    cout << "Z indeksu: \n";
    lista.usunPodIndeks(1);
    lista.wyswietl();

    cout << "\n=== Czyszczenie listy ===\n";

    lista.wyczysc();
    lista.wyswietl();

    return 0;
}