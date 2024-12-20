#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortHelpers.h"


void bubble_sort_list(Node** head) {
    if (*head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != ptr2) {
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                // Swap words
                char* temp = ptr1->word;
                ptr1->word = ptr1->next->word;
                ptr1->next->word = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

void insertion_sort_list(Node** head) {
    if (*head == NULL) return;

    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;

        if (sorted == NULL || strcmp(current->word, sorted->word) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->word, current->word) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

void sort_linked_list(Node** head, int choice) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    switch (choice) {
        case 1:
            bubble_sort_list(head);
            break;
        case 2:
            insertion_sort_list(head);
            break;
        default:
            printf("Invalid choice. Please select a valid sorting algorithm.\n");
            return;
    }
}