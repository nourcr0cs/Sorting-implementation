#include <stdio.h>
#include "sortHelpers.h"



void selection_sort(int* arr, int sz) {
    for (int end = sz - 1; end > 0; end--) {
        int max_idx = end;
        for (int i = end - 1; i >= 0; i--) {
            if (order_is_broken(arr, i, max_idx)) {
                max_idx = i;
            }
        }
        if (max_idx != end) {
            swap_items(arr, max_idx, end);
        }
    }
}
