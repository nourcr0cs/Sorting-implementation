#include <stdio.h>
#include "sortHelpers.h"



void comb_sort(int* arr, int sz) {
    const double factor = 1.2473309;
    int dif = sz;

    while (dif > 1) {
        dif = (int)(dif / factor);
        for (int i = 0; i + dif < sz; i++) {
            int j = i + dif;
            if (order_is_broken(arr, i, j)) {
                swap_items(arr, i, j);
            }
        }
    }
}
