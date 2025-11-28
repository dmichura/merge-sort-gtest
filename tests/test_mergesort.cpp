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

TEST(MergeSortTest, SingleElement) {
    vector<int> arr = {42};
    vector<int> expected = {42};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, Duplicates) {
    vector<int> arr = {3, 1, 2, 3, 1};
    vector<int> expected = {1, 1, 2, 3, 3};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, NegativeDuplicates) {
    vector<int> arr = {-3, -1, -2, -3, -1};
    vector<int> expected = {-3, -3, -2, -1, -1};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, MixedDuplicates) {
    vector<int> arr = {-2, 3, 0, -2, 3, 1};
    vector<int> expected = {-2, -2, 0, 1, 3, 3};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, TwoElementsSorted) {
    vector<int> arr = {1, 2};
    vector<int> expected = {1, 2};
    MergeSorter<int> sorter;
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, LargeArray) {
    vector<int> arr(150);
    generate(arr.begin(), arr.end(), rand);
    
    MergeSorter<int> sorter;
    sorter.sort(arr);
    
    EXPECT_EQ(arr.size(), 150);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}