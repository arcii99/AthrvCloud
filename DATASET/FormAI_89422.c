//FormAI DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
    int n, choice;
    int arr[MAX_SIZE];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nThe original array is: ");
    print_array(arr, n);
    
    printf("\nChoose a sorting algorithm (1: Bubble Sort, 2: Selection Sort, 3: Insertion Sort): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            bubble_sort(arr, n);
            printf("\nSorted array using Bubble Sort: ");
            print_array(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            printf("\nSorted array using Selection Sort: ");
            print_array(arr, n);
            break;
        case 3:
            insertion_sort(arr, n);
            printf("\nSorted array using Insertion Sort: ");
            print_array(arr, n);
            break;
        default:
            printf("\nInvalid choice!\n");
    }
    
    return 0;
}

void bubble_sort(int arr[], int n) {
    int temp, i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}