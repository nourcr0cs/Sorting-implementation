#include <stdio.h>
#include "sortHelpers.h"

void bubble_sort(int* arr, int n) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            // Use order_is_broken for comparison
            if (order_is_broken(arr, j, j + 1)) {
                // Use swap_items to swap elements
                swap_items(arr, j, j + 1);
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}


