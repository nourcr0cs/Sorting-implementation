#include "sortHelpers.h"
#include "sorting_algorithms.h"

void sort_matrix(char* matrix[], int rows, int cols, int ch) {
        for (int i = 0; i < rows; i++) {
            switch (ch)
            {
            case 1:
                bubble_sort(matrix[i], cols);  
                break;
            case 2:
                merge_sort_wrapper(matrix[i], int cols);
                break;
            default:
                printf("Invalid choice\n");
                return;
        }

    }

}
