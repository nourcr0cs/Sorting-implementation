#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "sortHelpers.h"



void merge(int* arr, int left, int mid, int right, int* temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        nbComp++; 
        if (!order_is_broken(arr, j, i)) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            nbPerm++; 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    // Print full array after merging
    printf("Array after merge (left=%d, right=%d): ", left, right);
    print_array(arr, right + 1); // Adjust for full array size
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

    nbComp = 0;
    nbPerm = 0;

    // Start the timer
    clock_t start_time = clock();

    merge_sort(arr, 0, sz - 1, temp);

    // Stop the timer
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    free(temp);

    // Display results
    printf("Sorting complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time: %.6f seconds\n", execution_time);

    // Time complexity analysis
    printf("Considering best and average case (O(nlog(n))):\n");
    double theoretical_best_avg = sz * log2(sz);
    printf("Theoretical Complexity (n * log2(n)): %.2f\n", theoretical_best_avg);
    printf("Experimental to Theoretical Ratio (nbComp / (n * log2(n))): %.2f\n", nbComp / theoretical_best_avg);

    printf("Considering worst case (O(n^2)):\n");
    double theoretical_worst = sz * sz;
    printf("Theoretical Complexity (n^2): %.2f\n", theoretical_worst);
    printf("Experimental to Theoretical Ratio (nbComp / n^2): %.2f\n", nbComp / theoretical_worst);
}
