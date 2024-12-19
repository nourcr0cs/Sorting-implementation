#include <stdio.h>
#include "sortHelpers.h"

void print_array(int arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_items(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    printf("Swapped %d and %d: ", arr[i], arr[j]);
    //to follow the sorting process (printing after swap)
    print_array(arr, sizeof(arr)/sizeof(arr[0]));  
    
}

int order_is_broken(int* arr, int i, int j) {
    return arr[i] > arr[j];
}
