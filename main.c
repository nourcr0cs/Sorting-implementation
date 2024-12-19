#include <stdio.h>
#include <stdlib.h>
#include "sorting/sortHelpers.h"
#include "sorting/sorting_algorithms.h"

int main()
{
    int choice;

    // Prompt for array size
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Prompt the user to enter the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Prompt for sorting algorithm choice
    printf("Choose a sorting algorithm:\n");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Bubble Sort\n");
    printf("6. Comb Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Sorting based on user choice
    switch (choice)
    {
    case 1:
        quick_sort_wrapper(arr, n);
        break;
    case 2:
        merge_sort_wrapper(arr, n);
        break;
    case 3:
        insertion_sort(arr, n);
        break;
    case 4:
        selection_sort(arr, n);
        break;
    case 5:
        bubble_sort(arr, n);
        break;
    case 6:
        comb_sort(arr, n);
        break;
    default:
        printf("Invalid choice! Please choose a valid sorting algorithm.\n");
        free(arr);  // Free memory before exiting
        return 1;
    }

    // Print sorted array
    printf("------------------------------------------- Sorted array: -------------------------------------------- \n");
    print_array(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
