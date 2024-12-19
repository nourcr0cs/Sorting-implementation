#include <stdio.h>
#include "sortHelpers.h"


void insertion_sort(int* arr, int sz) {
    for (int k = 1; k < sz; k++) {
        for (int i = k - 1; i >= 0; i--) {
            int j = i + 1;
            if (order_is_broken(arr, i, j)) {
                swap_items(arr, i, j);
            } else {
                break;
            }
        }
    }
}
