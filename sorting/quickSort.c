#include <stdio.h>
#include "sortHelpers.h"

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap_items(arr, i, j);
        }
    }
    swap_items(arr, i + 1, high);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void quick_sort_wrapper(int arr[], int sz)
{
    quick_sort(arr, 0, sz - 1);
}
