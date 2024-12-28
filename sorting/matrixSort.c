#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortHelpers.h"
#include <time.h>  
#include <math.h>  

void mergeM(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char** L = (char**)malloc(n1 * sizeof(char*));
    char** R = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        nbComp++;  
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

// Merge Sort Wrapper
void merge_sort_wrapper_m(char* arr[], int size) {
    clock_t start_time = clock(); 
    nbComp = 0;  
    nbPerm = 0;  

    merge_sort_strings(arr, 0, size - 1);

    clock_t end_time = clock();  // Stop measuring time
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Display results
    printf("\nMerge Sort Complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    // Complexity calculations
    printf("Best Case Complexity (O(n * log n)): %.2f\n", size * log2(size));
    printf("Worst Case Complexity (O(n * log n)): %.2f\n", size * log2(size));
    printf("Average Case Complexity (O(n * log n)): %.2f\n", size * log2(size));


    print_matrix(arr, size);
}

// Bubble Sort for strings
void bubble_sort_m(char* arr[], int sz) {
    clock_t start_time = clock();  // Start measuring time
    nbComp = 0;  // Reset global counters
    nbPerm = 0;

    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - i - 1; j++) {
            nbComp++;  // Increment comparison count
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                nbPerm++;  // Increment swap count
            }
        }
    }

    clock_t end_time = clock();  
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nBubble Sort Complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    printf("Best Case Complexity (O(n)): %d\n", sz);
    printf("Worst Case Complexity (O(n^2)): %d\n", sz * sz);
    printf("Average Case Complexity (O(n^2)): %d\n", sz * sz);

    print_matrix(arr, sz);
}

void sort_matrix(char* matrix[], int rows, int ch) {
    if (rows <= 0) {
        printf("The matrix is empty.\n");
        return;
    }

    switch (ch) {
        case 1:
            printf("Performing Bubble Sort on Matrix...\n");
            bubble_sort_m(matrix, rows);
            break;
        case 2:
            printf("Performing Merge Sort on Matrix...\n");
            merge_sort_wrapper_m(matrix, rows);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }}