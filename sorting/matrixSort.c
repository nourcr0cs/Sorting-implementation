#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortHelpers.h"

void mergeM(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char** L = (char**)malloc(n1 * sizeof(char*));
    char** R = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_strings(char* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_strings(arr, left, mid);
        merge_sort_strings(arr, mid + 1, right);
        mergeM(arr, left, mid, right);
    }
}

void merge_sort_wrapper_m(char* arr[], int size) {
    merge_sort_strings(arr, 0, size - 1);
}

void bubble_sort_m(char* arr[], int sz) {
    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_matrix(char* matrix[], int rows, int ch) {
    switch (ch) {
        case 1:
            bubble_sort_m(matrix, rows);
            break;
        case 2:
            merge_sort_wrapper_m(matrix, rows);
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
}
