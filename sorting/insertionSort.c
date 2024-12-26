#include <stdio.h>
#include <time.h>  // For measuring execution time
#include <math.h>  // For log2 function
#include "sortHelpers.h"



void insertion_sort(int* arr, int sz) {
    // Start measuring execution time
    clock_t start_time = clock();

    for (int k = 1; k < sz; k++) {
        for (int i = k - 1; i >= 0; i--) {
            int j = i + 1;
            nbComp++;  // Increment the comparison count

            // Compare and potentially swap
            if (order_is_broken(arr, i, j)) {
                swap_items(arr, i, j);
                nbPerm++;  
            } else {
                break;  
            }
        }
    }

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorting complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    double best_theoretical_complexity = sz;  
    double avg_theoretical_complexity = sz * sz;  
    double worst_theoretical_complexity = sz * sz; 
    printf("Best Case Complexity (O(n)): %.2f\n", best_theoretical_complexity);
    printf("Average Case Complexity (O(n^2)): %.2f\n", avg_theoretical_complexity);
    printf("Worst Case Complexity (O(n^2)): %.2f\n", worst_theoretical_complexity);
    printf("Experimental to Theoretical Ratio (nbComp / O(n^2)): %.2f\n", (double)nbComp / worst_theoretical_complexity);
}