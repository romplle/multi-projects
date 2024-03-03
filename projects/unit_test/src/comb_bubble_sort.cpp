#include "comb_bubble_sort.hpp"

using namespace std;

void CombBubbleSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    float shrink = 1.3;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = gap / shrink;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            int j = i + gap;
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
    }
}