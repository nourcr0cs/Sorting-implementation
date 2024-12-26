#include <stdio.h>
#include <time.h>  
#include <math.h>  
#include "sortHelpers.h"



void comb_sort(int* arr, int sz) {
    const double factor = 1.2473309;
    int dif = sz;

    
    clock_t start_time = clock();

    while (dif > 1) {
        dif = (int)(dif / factor);  
        
        for (int i = 0; i + dif < sz; i++) {
            int j = i + dif;

            nbComp++;

            if (order_is_broken(arr, i, j)) {
                swap_items(arr, i, j);
                nbPerm++;

                printf("Array after swap (gap=%d, i=%d, j=%d): ", dif, i, j);
                print_array(arr, sz);
            }
        }
    }

    //stop measuring execution time
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    printf("\nSorting complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    //finding the time complexity
    double theoretical_complexity = sz * log2(sz);
    printf("Considering best, average and worst case O(nlog(n)):");
    printf("Theoretical Complexity (n * log2(n)): %.2f\n", theoretical_complexity);
    printf("Experimental to Theoretical Ratio (nbComp / (n * log2(n))): %.2f\n", nbComp / theoretical_complexity);
}

