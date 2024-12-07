#include <stdio.h>
#include <stdlib.h>

void print_array(TYPE A[], int n) {
    /*
    A : the array to be printed
    n : the size of the array
    */
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(TYPE A[], int p, int q, int r, TYPE temp[], int n) {
    /* 
    p : start index of the first subarray
    q : end index of the first subarray (midpoint of the two subarrays)
    r : end index of the second subarray
    */

    int i, j, k;
    int nL = q - p + 1; // Length of the first subarray
    int nR = r - q;     // Length of the second subarray

    // Copy elements of the first subarray into the temporary array
    for (i = 0; i < nL; i++)    
        temp[p + i] = A[p + i];
    
    // Copy elements of the second subarray into the temporary array
    for (j = 0; j < nR; j++)    
        temp[q + 1 + j] = A[q + 1 + j];
    
    i = p;          // Pointer for the first subarray
    j = q + 1;      // Pointer for the second subarray
    k = p;          // Pointer for the merged array
    
    // Merge the two subarrays into the original array
    while (i <= q && j <= r) {
        if (temp[i] <= temp[j])  // Select the smaller element
            A[k++] = temp[i++];
        else  
            A[k++] = temp[j++];
    }
    
    // Copy any remaining elements from the first subarray
    while (i <= q) 
        A[k++] = temp[i++];
    
    // Copy any remaining elements from the second subarray
    while (j <= r) 
        A[k++] = temp[j++];
    
    // Print the state of the array after each merge
    printf("Array after merging from index %d to %d: ", p, r);
    print_array(A, n);
}

void merge_sort(TYPE A[], int p, int r, TYPE temp[], int n) {
    /*
    A : the array to be sorted
    p : start index of the array
    r : end index of the array
    */
    if (p < r) {
        int q = (p + r) / 2; // Find the midpoint of the array

        // Recursively sort the first half
        merge_sort(A, p, q, temp, n);

        // Recursively sort the second half
        merge_sort(A, q + 1, r, temp, n);

        // Merge the two sorted halves
        merge(A, p, q, r, temp, n);
    }
}

void merge_sort_wrapper(TYPE A[], int n) {
    /*
    A : the array to be sorted
    n : the size of the array
    */
    // Allocate a temporary array for the merge process
    TYPE *temp = malloc(n * sizeof(TYPE));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Call the merge sort function
    merge_sort(A, 0, n - 1, temp, n);

    // Free the allocated memory for the temporary array
    free(temp);
}

int main() {
    // Replace TYPE with a specific type (e.g., int or long)
    #define TYPE int

    TYPE array[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Initial array: ");
    print_array(array, n);

    merge_sort_wrapper(array, n);

    printf("Sorted array: ");
    print_array(array, n);

    return 0;
}
