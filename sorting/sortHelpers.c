#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  
#include "sortHelpers.h"

void print_array(int arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void generate_random_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; 
    }
}


void swap_items(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;    
}

int order_is_broken(int* arr, int i, int j) {
    return arr[i] > arr[j];
}

void swap_items_list(Node* a, Node* b) {
    char temp[100];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
    printf("Swapped %s and %s\n", a->word, b->word);
}

int order_is_broken_list(const char* a, const char* b) {
    return strcmp(a, b) > 0; 
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}


void print_matrix(char* matrix[], int rows) {
    printf("[ ");
    for (int i = 0; i < rows; i++) {
        printf("\"%s\"", matrix[i]);
        if (i < rows - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void add_word(Node** head, const char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->word = strdup(word); // Allocate memory for the string
    new_node->next = *head;
    *head = new_node;
}

