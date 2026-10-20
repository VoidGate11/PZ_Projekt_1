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

    // Oczekiwany wynik: 10 20 30 40 50
    lista.wyswietl();

    cout << "\n=== Wyswietlenie odwrotne ===\n";

    // Oczekiwany wynik: 50 40 30 20 10
    lista.wyswietlOdwrotnie();

    cout << "\n=== Iterator ===\n";

    // Iterator zaczyna od początku listy.
    lista.wyswietlNastepny();
    lista.wyswietlNastepny();
    lista.wyswietlNastepny();

    // Iterator znajduje się teraz na elemencie 40.
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