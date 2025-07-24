//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int arr[10] = {7, 3, 2, 9, 4, 6, 8, 1, 5, 0};  // initialize array with 10 elements
    int i, j, temp;
    int n = sizeof(arr) / sizeof(arr[0]);  // calculate length of array
    
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // bubble sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {  // swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}