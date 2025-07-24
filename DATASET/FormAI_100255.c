//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main() {
    int *arr = (int *) malloc(sizeof(int) * ARRAY_SIZE);

    // Initialize array with numbers in reverse order
    for(int i = ARRAY_SIZE - 1; i >= 0; i--) {
        arr[i] = ARRAY_SIZE - i;
    }

    // Bubble sort
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print sorted array
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}