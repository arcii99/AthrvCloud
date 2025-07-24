//FormAI DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    // create an array of integers
    int arr[10] = { 4, 3, 6, 8, 1, 9, 2, 5, 7, 0 };
    int n = 10;
    
    // print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // implement bubble sort algorithm
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}