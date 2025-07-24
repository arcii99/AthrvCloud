//FormAI DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>

// Declaration of function pointers
typedef void (*sort_fn)(int arr[], int n);

// Bubble sort implementation
void bubble_sort(int arr[], int n) {
    int temp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection sort implementation
void selection_sort(int arr[], int n) {
    int min_index, temp;
    for(int i=0; i<n-1; i++) {
        min_index = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Insertion sort implementation
void insertion_sort(int arr[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int array[7] = {7, 4, 5, 1, 3, 2, 6};

    // Array before sorting
    printf("Array before sorting: ");
    for(int i=0; i<7; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Array after bubble sort
    sort_fn bubbleSort = bubble_sort;
    bubbleSort(array, 7);
    printf("Array after bubble sort: ");
    for(int i=0; i<7; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Array after selection sort
    sort_fn selectionSort = selection_sort;
    selectionSort(array, 7);
    printf("Array after selection sort: ");
    for(int i=0; i<7; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Array after insertion sort
    sort_fn insertionSort = insertion_sort;
    insertionSort(array, 7);
    printf("Array after insertion sort: ");
    for(int i=0; i<7; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}