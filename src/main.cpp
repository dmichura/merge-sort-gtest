/**
 * @file main.cpp
 * @brief Plik główny demonstrujący działanie algorytmu Merge Sort.
 *
 * Plik zawiera funkcję main, która tworzy instancje klasy MergeSorter
 * dla różnych typów danych (int, double) i prezentuje wyniki sortowania
 * na standardowym wyjściu.
 */

#include <iostream>
#include <vector>
#include "MergeSorter.h"

using namespace std;

/**
 * @brief Wyświetla zawartość wektora na standardowym wyjściu.
 *
 * Funkcja pomocnicza iterująca przez elementy wektora i wypisująca je
 * oddzielone spacją. Na końcu wypisywany jest znak nowej linii.
 *
 * @tparam T Typ danych przechowywanych w wektorze (musi obsługiwać operator<<).
 * @param arr Stała referencja do wektora, którego elementy mają zostać wyświetlone.
 */
template <typename T>
void printArray(const vector<T>& arr) {
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

/**
 * @brief Główny punkt wejścia programu.
 *
 * Funkcja przeprowadza demonstrację sortowania dla dwóch typów danych:
 * 1. Liczb całkowitych (int).
 * 2. Liczb zmiennoprzecinkowych (double).
 *
 * Dla każdego typu tworzony jest wektor, wyświetlany jest stan przed sortowaniem,
 * następuje sortowanie, a na końcu wyświetlany jest wynik.
 *
 * @return int Kod statusu zakończenia programu (0 oznacza sukces).
 */
int main() {
    // Demonstracja dla typu int
    vector<int> intTab = { 12, -5, 0, 7, 3, 12, -1, 49, 31 };
    MergeSorter<int> intSorter;
    
    cout << "NO SORT | ";
    printArray(intTab);
    
    intSorter.sort(intTab);
    
    cout << "SORTED  | ";
    printArray(intTab);

    // Demonstracja dla typu double
    vector<double> doubleTab = { 3.14, -1.1, 0.0, 2.5, 3.14, -0.5, -4.4, 5.96 };
    MergeSorter<double> doubleSorter;

    cout << "NO SORT | ";
    printArray(doubleTab);
    
    doubleSorter.sort(doubleTab);
    
    cout << "SORTED  | ";
    printArray(doubleTab);

    return 0;
}