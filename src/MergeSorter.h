#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <vector>

using namespace std;

template <typename T>
class MergeSorter {
    private:
        void merge(vector<T>& array, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            vector<T> L(n1);
            vector<T> R(n2);

            for (int i = 0; i < n1; i++)
                L[i] = array[left + i];
            for (int j = 0; j < n2; j++)
                R[j] = array[mid + 1 + j];

            int i = 0;
            int j = 0;
            int k = left;

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

            while (i < n1) {
                array[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                array[k] = R[j];
                j++;
                k++;
            }
        }
    public:
};

#endif