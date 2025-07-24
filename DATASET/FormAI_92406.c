//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>

int main() {
    int arr[] = {5, 3, 2, 7, 1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    // Implement Bubble Sort Algorithm
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap the numbers
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}