/**
 * @file test_mergesort.cpp
 * @brief Zestaw testów jednostkowych dla algorytmu Merge Sort.
 *
 * Plik wykorzystuje framework Google Test do weryfikacji poprawności działania
 * szablonu klasy MergeSorter. Testy pokrywają przypadki brzegowe,
 * typowe scenariusze oraz testy obciążeniowe.
 */

#include <gtest/gtest.h>
#include "../src/MergeSorter.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

/**
 * @brief Sprawdza zachowanie dla tablicy już posortowanej.
 *
 * Oczekiwane zachowanie: Tablica pozostaje niezmieniona.
 */
TEST(MergeSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Sprawdza sortowanie tablicy posortowanej odwrotnie (malejąco).
 *
 * Jest to jeden z przypadków, w których algorytm musi wykonać najwięcej przestawień (w scalaniu).
 */
TEST(MergeSortTest, ReverseSorted) {
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Testuje sortowanie losowej tablicy liczb.
 *
 * Weryfikuje ogólną poprawność algorytmu na nieuporządkowanych danych.
 * Wykorzystuje std::is_sorted do weryfikacji wyniku.
 */
TEST(MergeSortTest, RandomArray) {
    vector<int> arr = {10, 2, 8, 1, 5, 9};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

/**
 * @brief Weryfikuje sortowanie tablicy zawierającej tylko liczby ujemne.
 *
 * Sprawdza, czy algorytm poprawnie interpretuje relacje mniejszości dla liczb ujemnych.
 */
TEST(MergeSortTest, OnlyNegative) {
    vector<int> arr = {-5, -1, -10, -3, -2};
    vector<int> expected = {-10, -5, -3, -2, -1};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Sprawdza sortowanie mieszanki liczb dodatnich i ujemnych.
 *
 * Testuje poprawne ustawienie liczb ujemnych przed zerem i liczbami dodatnimi.
 */
TEST(MergeSortTest, MixedNegativePositive) {
    vector<int> arr = {-5, 10, 0, -3, 2};
    vector<int> expected = {-5, -3, 0, 2, 10};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Testuje obsługę pustej tablicy.
 *
 * Algorytm nie powinien rzucić wyjątkiem ani naruszyć pamięci.
 * Tablica po operacji powinna pozostać pusta.
 */
TEST(MergeSortTest, EmptyArray) {
    vector<int> arr = {};
    MergeSorter<int> sorter;
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

/**
 * @brief Sprawdza przypadek brzegowy z jednym elementem.
 *
 * Tablica jednoelementowa jest z definicji posortowana. Algorytm nie powinien jej zmieniać.
 */
TEST(MergeSortTest, SingleElement) {
    vector<int> arr = {42};
    vector<int> expected = {42};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Testuje poprawność sortowania tablicy z duplikatami.
 *
 * Algorytm powinien zgrupować te same wartości obok siebie.
 */
TEST(MergeSortTest, Duplicates) {
    vector<int> arr = {3, 1, 2, 3, 1};
    vector<int> expected = {1, 1, 2, 3, 3};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Sprawdza sortowanie duplikatów wśród liczb ujemnych.
 */
TEST(MergeSortTest, NegativeDuplicates) {
    vector<int> arr = {-3, -1, -2, -3, -1};
    vector<int> expected = {-3, -3, -2, -1, -1};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Testuje mieszane wartości (dodatnie, ujemne, zero) z duplikatami.
 *
 * Najbardziej złożony przypadek dla małej liczby danych.
 */
TEST(MergeSortTest, MixedDuplicates) {
    vector<int> arr = {-2, 3, 0, -2, 3, 1};
    vector<int> expected = {-2, -2, 0, 1, 3, 3};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Sprawdza poprawność dla małej tablicy (2 elementy).
 *
 * Podstawowy krok rekurencji (po podziale tablicy 4-elementowej).
 */
TEST(MergeSortTest, TwoElementsSorted) {
    vector<int> arr = {1, 2};
    vector<int> expected = {1, 2};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test wydajnościowy/poprawności dla dużej tablicy losowej.
 *
 * Tablica zawiera 150 losowych elementów generowanych funkcją rand().
 */
TEST(MergeSortTest, LargeArray) {
    vector<int> arr(150);
    generate(arr.begin(), arr.end(), rand);
    
    MergeSorter<int> sorter;
    sorter.sort(arr);
    
    EXPECT_EQ(arr.size(), 150);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

/**
 * @brief Zaawansowany test dużej tablicy (ujemne, dodatnie, duplikaty).
 *
 * Generuje ręcznie zestaw danych zawierający wszystkie typy liczb,
 * a następnie miesza je losowo przed sortowaniem.
 */
TEST(MergeSortTest, LargeComplexArray) {
    vector<int> arr;
    for(int i=0; i<50; ++i) arr.push_back(i);       // Dodatnie
    for(int i=0; i<50; ++i) arr.push_back(-i);      // Ujemne
    for(int i=0; i<20; ++i) arr.push_back(5);       // Duplikaty dodatnie
    for(int i=0; i<20; ++i) arr.push_back(-5);      // Duplikaty ujemne
    
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    
    MergeSorter<int> sorter;
    sorter.sort(arr);
    
    EXPECT_GE(arr.size(), 140);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}