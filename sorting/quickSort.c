#include <stdio.h>
#include <time.h>  // For measuring execution time
#include <math.h>  // For log2 function
#include "sortHelpers.h"


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        nbComp++;  
        if (arr[j] <= pivot) {
            i++;
            swap_items(arr, i, j);
            nbPerm++;  
        }
    }
    swap_items(arr, i + 1, high);
    nbPerm++;  
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
    clock_t start_time = clock();

    quick_sort(arr, 0, sz - 1);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorting complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    //Time complexity (theoretical approximation)
    double best_theoretical_complexity = sz * log2(sz);  
    double avg_theoretical_complexity = sz * log2(sz);  
    double worst_theoretical_complexity = sz * sz;  
    printf("Best Case Complexity (O(n log n)): %.2f\n", best_theoretical_complexity);
    printf("Average Case Complexity (O(n log n)): %.2f\n", avg_theoretical_complexity);
    printf("Worst Case Complexity (O(n^2)): %.2f\n", worst_theoretical_complexity);
    printf("Experimental to Theoretical Ratio (nbComp / O(n log n)): %.2f\n", (double)nbComp / avg_theoretical_complexity);
}