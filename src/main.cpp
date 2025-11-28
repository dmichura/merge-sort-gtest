#include <iostream>
#include <vector>
#include "MergeSorter.h"

using namespace std;

template <typename T>
void printArray(const vector<T>& arr) {
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> intTab = { 12, -5, 0, 7, 3, 12, -1, 49, 31 };
    MergeSorter<int> intSorter;
    
    printArray(intTab);
    intSorter.sort(intTab);
    printArray(intTab);

    vector<double> doubleTab = { 3.14, -1.1, 0.0, 2.5, 3.14, -0.5, -4.4, 5.96 };
    MergeSorter<double> doubleSorter;
    
    printArray(doubleTab);
    doubleSorter.sort(doubleTab);
    printArray(doubleTab);
    return 0;
}