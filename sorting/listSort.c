#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortHelpers.h"
#include <time.h>  
#include <math.h>  


void bubble_sort_list(Node** head) {
    if (*head == NULL) return;

    clock_t start_time = clock();  // Start measuring time
    int swapped;
    Node* ptr1;
    Node* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != ptr2) {
            nbComp++;  // Increment comparison count
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                // Swap words
                char* temp = ptr1->word;
                ptr1->word = ptr1->next->word;
                ptr1->next->word = temp;
                swapped = 1;
                nbPerm++;  // Increment permutation count
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);

    clock_t end_time = clock();  // Stop measuring time
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Display results
    printf("\nBubble Sort (Linked List) Complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    // Time Complexity calc
    printf("Best Case Complexity (O(n)): n = %d\n", nbComp); //no swaps in sorted case
    printf("Worst Case Complexity (O(n^2)): n^2 = %d\n", nbComp);
    printf("Average Case Complexity (O(n^2)): n^2 = %d\n", nbComp);

    // Print sorted list
    print_list(*head);
}

// Insertion Sort for linked lists
void insertion_sort_list(Node** head) {
    if (*head == NULL) return;

    clock_t start_time = clock();  // Start measuring time
    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;

        nbComp++;  
        if (sorted == NULL || strcmp(current->word, sorted->word) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->word, current->word) < 0) {
                temp = temp->next;
                nbComp++;
            }
            current->next = temp->next;
            temp->next = current;
        }
        nbPerm++;  
        current = next;
    }
    *head = sorted;

    clock_t end_time = clock();  // Stop measuring time
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nInsertion Sort (Linked List) Complete.\n");
    printf("Number of comparisons (nbComp): %d\n", nbComp);
    printf("Number of permutations (nbPerm): %d\n", nbPerm);
    printf("Execution time (Tps): %.6f seconds\n", execution_time);

    // Complexity calculations
    printf("Best Case Complexity (O(n)): n = %d\n", nbComp); // Sorted case, no swaps
    printf("Worst Case Complexity (O(n^2)): n^2 = %d\n", nbComp);
    printf("Average Case Complexity (O(n^2)): n^2 = %d\n", nbComp);

      print_list(*head);
}

// Sorting Controller Function with performance reset
void sort_linked_list(Node** head, int choice) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    nbComp = 0;  // Reset comparison counter
    nbPerm = 0;  // Reset permutation counter

    switch (choice) {
        case 1:
            printf("Performing Bubble Sort on Linked List...\n");
            bubble_sort_list(head);
            break;
        case 2:
            printf("Performing Insertion Sort on Linked List...\n");
            insertion_sort_list(head);
            break;
        default:
            printf("Invalid choice. Please select a valid sorting algorithm.\n");
            return;
    } }