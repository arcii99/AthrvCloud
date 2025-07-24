//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>

int main() {
    int arr[10] = {5, 9, 3, 11, 7, 2, 4, 10, 1, 6}; // My array of excitement!
    int n = 10, i, j;

    printf("Unsorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nLet's sort this array with excitement! Here we go....\n");

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Displaying my sorted array with joy!
    printf("\nSorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nWooHoo! We did it! The array is now sorted with excitement.\n");

    return 0;
}