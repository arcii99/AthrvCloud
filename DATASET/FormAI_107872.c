//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main() {

    // Allocate memory for large arrays
    int* arr1 = (int*) malloc(MAX_SIZE * sizeof(int));
    int* arr2 = (int*) malloc(MAX_SIZE * sizeof(int));

    // Initialize arrays
    for(int i=0; i<MAX_SIZE; i++) {
        arr1[i] = i;
        arr2[i] = MAX_SIZE - i - 1;
    }

    // Sequential access to arrays
    for(int i=0; i<MAX_SIZE; i++) {
        arr1[i]++;
        arr2[i]--;
    }

    // Copy arrays data to other arrays
    int* arr3 = (int*) malloc(MAX_SIZE * sizeof(int));
    int* arr4 = (int*) malloc(MAX_SIZE * sizeof(int));
    memcpy(arr3, arr1, MAX_SIZE * sizeof(int));
    memcpy(arr4, arr2, MAX_SIZE * sizeof(int));

    // Random access to arrays
    for(int i=0; i<MAX_SIZE; i++) {
        int index = rand() % MAX_SIZE;
        arr3[index]++;
        arr4[index]--;
    }

    // Free allocated memory
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}