#include <gtest/gtest.h>
#include "../src/MergeSorter.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

TEST(MergeSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, ReverseSorted) {
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomArray) {
    vector<int> arr = {10, 2, 8, 1, 5, 9};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(MergeSortTest, OnlyNegative) {
    vector<int> arr = {-5, -1, -10, -3, -2};
    vector<int> expected = {-10, -5, -3, -2, -1};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, MixedNegativePositive) {
    vector<int> arr = {-5, 10, 0, -3, 2};
    vector<int> expected = {-5, -3, 0, 2, 10};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, EmptyArray) {
    vector<int> arr = {};
    MergeSorter<int> sorter;
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}