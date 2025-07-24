//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 1, 4, 2}; // Array to be sorted
    int i, j, temp;

    printf("Array before sorting: ");
    for(i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble sort algorithm
    for(i=0; i<4; i++) {
        for(j=0; j<4-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nArray after sorting: ");
    for(i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}