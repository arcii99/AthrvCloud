//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// function declarations
void insertion_sort(int arr[], int size);
void print_array(int arr[], int size);

int main() {
    printf("\n--------------\n");
    printf("SORTING EXAMPLE\n");
    printf("--------------\n\n");

    // create an array of integers
    int arr[] = {32, 1, 87, 23, 56, 9, 43, 8, 72, 14};

    // find the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: \n");
    print_array(arr, size);

    // sort the array using insertion sort
    insertion_sort(arr, size);

    printf("\nSorted Array: \n");
    print_array(arr, size);

    printf("\n--------------\n");
    printf("END OF PROGRAM\n");
    printf("--------------\n");

    return 0;
}

// insertion sort implementation
void insertion_sort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

// print the contents of an array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}