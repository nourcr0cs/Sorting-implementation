#include <stdio.h>
#include <stdlib.h>
#include "sortHelpers.h"

void merge(int* arr, int left, int mid, int right, int* temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (!order_is_broken(arr, j, i)) 
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }

    while (i <= mid) 
        temp[k++] = arr[i++];

    while (j <= right) 
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++) 
        arr[i] = temp[i];
}

void merge_sort(int* arr, int left, int right, int* temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid, temp);
        merge_sort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

void merge_sort_wrapper(int* arr, int sz) {
    int* temp = malloc(sz * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    merge_sort(arr, 0, sz - 1, temp);
    free(temp);
}
