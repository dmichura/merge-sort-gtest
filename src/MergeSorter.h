/**
 * @file MergeSorter.h
 * @brief Implementacja szablonowa algorytmu sortowania przez scalanie (Merge Sort).
 *
 * Plik zawiera definicję klasy MergeSorter, która umożliwia sortowanie
 * wektorów dowolnego typu, pod warunkiem, że typ ten obsługuje operatory porównania.
 */

#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <vector>

using namespace std;

/**
 * @class MergeSorter
 * @brief Klasa realizująca algorytm sortowania przez scalanie.
 *
 * Klasa wykorzystuje strategię "dziel i zwyciężaj" (Divide and Conquer).
 * Algorytm dzieli tablicę na połówki, sortuje je rekurencyjnie, a następnie scala.
 *
 * @tparam T Typ danych przechowywanych w wektorze. Musi posiadać operator porównania <=.
 */
template <typename T>
class MergeSorter {
    private:
        /**
         * @brief Scala dwie posortowane podtablice w jedną.
         *
         * Funkcja pomocnicza, która łączy dwie podtablice tablicy[left..mid]
         * oraz tablicy[mid+1..right] w jedną posortowaną sekwencję.
         * Wykorzystuje dodatkową pamięć na tymczasowe tablice L i R.
         *
         * @param array Referencja do wektora, na którym wykonywana jest operacja.
         * @param left Indeks początkowy pierwszej podtablicy.
         * @param mid Indeks środkowy (koniec pierwszej podtablicy).
         * @param right Indeks końcowy drugiej podtablicy.
         */
        void merge(vector<T>& array, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            // Tworzenie tymczasowych wektorów
            vector<T> L(n1);
            vector<T> R(n2);

            // Kopiowanie danych do tymczasowych wektorów L[] i R[]
            for (int i = 0; i < n1; i++)
                L[i] = array[left + i];
            for (int j = 0; j < n2; j++)
                R[j] = array[mid + 1 + j];

            int i = 0; // Indeks początkowy pierwszej podtablicy
            int j = 0; // Indeks początkowy drugiej podtablicy
            int k = left; // Indeks początkowy scalonej tablicy

            // Scalanie tymczasowych tablic z powrotem do array[left..right]
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    array[k] = L[i];
                    i++;
                } else {
                    array[k] = R[j];
                    j++;
                }
                k++;
            }

            // Kopiowanie pozostałych elementów L[], jeśli są
            while (i < n1) {
                array[k] = L[i];
                i++;
                k++;
            }

            // Kopiowanie pozostałych elementów R[], jeśli są
            while (j < n2) {
                array[k] = R[j];
                j++;
                k++;
            }
        }

        /**
         * @brief Rekurencyjna funkcja sortująca.
         *
         * Dzieli tablicę na dwie połowy do momentu, gdy podtablica ma rozmiar 1,
         * a następnie wywołuje funkcję merge() do scalenia posortowanych części.
         *
         * @param array Referencja do sortowanego wektora.
         * @param left Indeks lewego końca zakresu sortowania.
         * @param right Indeks prawego końca zakresu sortowania.
         */
        void mergeSortRecursive(vector<T>& array, int left, int right) {
            if (left < right) {
                // Obliczanie środka, chroni przed przepełnieniem (overflow) dla dużych int
                int mid = left + (right - left) / 2;

                // Sortuj pierwszą i drugą połowę
                mergeSortRecursive(array, left, mid);
                mergeSortRecursive(array, mid + 1, right);

                // Scal posortowane połowy
                merge(array, left, mid, right);
            }
        }

    public:
        /**
         * @brief Publiczna metoda do sortowania wektora.
         *
         * Jest to interfejs publiczny klasy. Sprawdza warunki brzegowe
         * (pusta tablica lub jeden element) i uruchamia algorytm rekurencyjny.
         *
         * Złożoność czasowa: \f$ O(n \log n) \f$ we wszystkich przypadkach (średni, najgorszy, najlepszy).
         * Złożoność pamięciowa: \f$ O(n) \f$ (wymaga dodatkowej pamięci na scalanie).
         *
         * @param array Referencja do wektora, który ma zostać posortowany.
         */
        void sort(vector<T>& array) {
            if (array.size() <= 1) {
                return; // Tablica jest już posortowana
            }
            mergeSortRecursive(array, 0, array.size() - 1);
        }
};

#endif