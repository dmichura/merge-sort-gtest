# Implementacja Merge Sort w C++ (Google Test)

Ten projekt zawiera implementację algorytmu **Sortowania przez Scalanie (Merge Sort)** napisaną w języku C++. Projekt wykorzystuje **templates**, dzięki czemu możliwe jest sortowanie wektorów zawierających różne typy danych (np. `int`, `double`)

Poprawność algorytmu weryfikowana jest za pomocą **testów jednostkowych** opartych na frameworku Google Test.
## Funkcjonalności

* **Algorytm Merge Sort**: Stabilne sortowanie o złożoności $O(n \log n)$.
* **Generyczność**: Klasa `MergeSorter<T>` obsługuje dowolny typ danych wspierający operatory porównania.
* **Wsparcie dla wektorów**: Bezpośrednia praca na kontenerach `std::vector`.
* **Testy automatyczne**: Zintegrowane środowisko Google Test (pobierane automatycznie przez CMake).

## Struktura Projektu

```text
.
├── CMakeLists.txt       # Konfiguracja budowania (pobiera GTest)
├── README.md            # Dokumentacja
├── run.bat / run.sh     # Skrypty uruchamiające główną aplikację
├── test.bat / test.sh   # Skrypty uruchamiające testy
├── src/
│   ├── main.cpp         # Demonstracja działania (int oraz double)
│   └── MergeSorter.h    # Implementacja algorytmu (szablon klasy)
└── tests/
    └── test_mergesort.cpp # Scenariusze testowe (Google Test)
```
## Wymagania
* **Kompilator C++**: Obsługujący standard C++14.
* **CMake**: Wersja 3.14 lub nowsza.
* **Doxygen** (Opcjonalnie)
## Kompilacja i Uruchomienie (Deployment)

Projekt posiada gotowe skrypty automatyzujące proces budowania.

### 1. Uruchomienie Aplikacji
Uruchamia kod z pliku `src/main.cpp`, sortujący przykładowe tablice liczb całkowitych i zmiennoprzecinkowych.

* **Linux (Terminal):**
    ```bash
    ./run.sh
    ```
* **Windows (CMD):**
    ```cmd
    run.bat
    ```

### 2. Uruchomienie Testów
Kompiluje i uruchamia zestaw testów zdefiniowanych w `tests/test_mergesort.cpp`.

* **Linux (Terminal):**
    ```bash
    ./test.sh
    ```
* **Windows (CMD):**
    ```cmd
    test.bat
    ```

## Zakres Testów (Google Test)

Zaimplementowano 13 testów pokrywających skrajne przypadki:

1.  **AlreadySorted**: Tablica już posortowana nie ulega zmianie.
2.  **ReverseSorted**: Sortowanie tablicy ułożonej malejąco.
3.  **RandomArray**: Sortowanie losowych danych.
4.  **OnlyNegative**: Obsługa liczb ujemnych.
5.  **MixedNegativePositive**: Mieszanka liczb dodatnich, ujemnych i zera.
6.  **EmptyArray**: Bezpieczna obsługa pustego wektora (brak wyjątków).
7.  **SingleElement**: Obsługa wektora jednoelementowego.
8.  **Duplicates**: Poprawne sortowanie powtarzających się liczb.
9.  **NegativeDuplicates**: Duplikaty wśród liczb ujemnych.
10. **MixedDuplicates**: Duplikaty mieszane.
11. **TwoElementsSorted**: Mała tablica (2 elementy).
12. **LargeArray**: Test wydajnościowy na wektorze 150 elementowym.
13. **LargeComplexArray**: Duży wektor z liczbami ujemnymi, dodatnimi i duplikatami.

## Autor

* Dawid Michura - [dmichura](https://github.com/dmichura)