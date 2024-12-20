#ifndef SORT_HELPERS_H
#define SORT_HELPERS_H

typedef struct Node {
    char* word;
    struct Node* next; 
} Node;

int order_is_broken(int* arr, int i, int j);
void swap_items(int* arr, int i, int j);
void print_array(int A[], int n);
void swap_items_list(Node* a, Node* b);
int order_is_broken_list(const char* a, const char* b);
void print_list(Node* head);
void print_matrix(char* matrix[], int rows);
void add_word(Node** head, const char* word);
#endif 
