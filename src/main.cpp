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
    cout << "Hello world\n";
    return 0;
}