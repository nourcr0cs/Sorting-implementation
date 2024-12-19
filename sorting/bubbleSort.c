#include <stdio.h>
#include "sortHelpers.h"

void bubble_sort(int* arr, int sz) {
    int i, j;
    int swapped;

    for (i = 0; i < sz - 1; i++) {
        swapped = 0;

        for (j = 0; j < sz - i - 1; j++) {
            //to compare
            if (order_is_broken(arr, j, j + 1)) {
                //the ordinary swap once needed
                swap_items(arr, j, j + 1);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}


