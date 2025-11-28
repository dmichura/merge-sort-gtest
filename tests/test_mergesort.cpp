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