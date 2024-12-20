#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <stdlib.h> 
#include <string.h>  



// all necessary func for the main
void quick_sort_wrapper(int arr[], int sz);
void merge_sort_wrapper(int arr[], int sz);
void insertion_sort(int arr[], int sz);
void selection_sort(int arr[], int sz);
void bubble_sort(int arr[], int sz);
void comb_sort(int arr[], int sz);
void bubble_sort_m(char* arr[], int sz);
void bubble_sort_list(Node** head);
void insertion_sort_list(Node** head);
void append_node(Node** head, const char* str);
void merge_sort_wrapper_m(char* arr[], int size);
void merge_sort_strings(char* arr[], int left, int right);
void merge(char* arr[], int left, int mid, int right);
void sort_linked_list(Node** head, int order);
void sort_matrix(char* matrix[], int rows, int order);


#endif
