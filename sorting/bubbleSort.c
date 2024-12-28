#include <stdio.h>
#include <time.h>  
#include <math.h>  
#include "sortHelpers.h"


void bubble_sort(int* arr, int sz) {
  
    clock_t start_time = clock();
    int swapped;

    for (int i = 0; i < sz - 1; i++) {
        swapped = 0;

        for (int j = 0; j < sz - i - 1; j++) {
            nbComp++;  

         
            if (order_is_broken(arr, j, j + 1)) {
                swap_items(arr, j, j + 1);
                nbPerm++; 
                swapped = 1;
                print_array(arr, sz);
            }
        }

       
        if (!swapped) {
            break;
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