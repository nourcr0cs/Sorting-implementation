#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting/sortHelpers.h"
#include "sorting/sorting_algorithms.h"


int nbComp = 0;
int nbPerm = 0;

void print_menu() {
    printf("Choose a data structure to sort:\n");
    printf("1. Array of integers\n");
    printf("2. List of strings\n");
    printf("3. Matrix of characters\n");
    printf("Enter your choice: ");
}



int main() {
    int dataChoice, sortChoice;

    print_menu();
    scanf("%d", &dataChoice);

    if (dataChoice == 1) {
        int n;
        printf("Enter the number of elements in the array: ");
        scanf("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("%d elements are being entered automatically... :\n", n);
        generate_random_array(arr, n);
        /*for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }*/
      //menu to make the user choose the sorting algorithm
        printf("Choose a sorting algorithm:\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Bubble Sort\n");
        printf("6. Comb Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &sortChoice);

        switch (sortChoice) {
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
            printf("Invalid sorting choice!\n");
            free(arr);
            return 1;
        }

        printf("Sorted array:\n");
        print_array(arr, n);
        free(arr);

    } else if (dataChoice == 2) {
        int n, sortChoice;
        Node* list = NULL;

        printf("Enter the number of strings: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            char str[100];
            printf("Enter string %d: ", i + 1);
            scanf("%s", str);
            add_word(&list, str);
        }

        printf("Original list:\n");
        print_list(list);

        printf("\nChoose a sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &sortChoice);

        sort_linked_list(&list, sortChoice);

        printf("\nSorted list of strings:\n");
        print_list(list);

        //Free memory
        Node* temp;
        while (list != NULL) {
            temp = list;
            list = list->next;
            free(temp->word);
            free(temp);
        }

    } else if (dataChoice == 3) {
        int rows, cols;
        printf("Enter the number of rows (numbers of words): ");
        scanf("%d", &rows);
        printf("Enter the maximum number of characters in each string (to define cols): ");
        scanf("%d", &cols);
        
        char** matrix = (char**)malloc(rows * sizeof(char*));
        for (int i = 0; i < rows; i++) {
            matrix[i] = (char*)malloc((cols + 1) * sizeof(char));  
            printf("Enter string %d: ", i + 1);
            scanf("%s", matrix[i]); 
        }


        printf("Choose a sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &sortChoice);
            
        printf("Original matrix:\n");
        print_matrix(matrix, rows);

        
            switch (sortChoice) {
            case 1:
                sort_matrix(matrix, rows, 1);
                break;
            case 2:
                sort_matrix(matrix, rows, 2);
                break;
            default:
                printf("Invalid sorting choice!\n");
                for (int j = 0; j < rows; j++) free(matrix[j]);
                free(matrix);
                return 1;
            }

        printf("Sorted matrix of characters row by row:\n");
        print_matrix(matrix, rows);
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);

    } else {
        printf("Invalid data structure choice!\n");
        return 1;
    }

    return 0;

}