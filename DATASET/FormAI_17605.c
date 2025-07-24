//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

// A cheerful sorting program!
// It's time to sort things out! 😎

int main() {
    int arr[] = {7, 3, 8, 9, 2, 5, 1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp;

    // Let's print the unsorted array first!
    printf("Unsorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // It's time to sort this array!
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                // Let's swap these elements!
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Yay! We did it! Let's print the sorted array now!
    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}