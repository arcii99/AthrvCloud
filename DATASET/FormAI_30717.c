//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Memory Manager program!\n");

    // Allocate memory for an integer array of size 5
    int* arr = (int*)malloc(sizeof(int)*5);

    if (arr == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return 1;
    } else {
        printf("Memory allocation successful!\n");

        // Assign values to the array elements
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        // Print the array elements
        printf("The array elements are: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Deallocate the memory
        free(arr);
        printf("Memory deallocation successful!\n");
    }

    return 0;
}