//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int arr[ARRAY_SIZE];
    int i;

    // Initialize array with random values
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Sort array
    int j, temp;
    for(i = 0; i < ARRAY_SIZE - 1; i++) {
        for(j = i + 1; j < ARRAY_SIZE; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print array elements
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}