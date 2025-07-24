//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int *ptr = NULL;
    ptr = (int*)malloc(SIZE * sizeof(int)); // Allocating memory dynamically

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory allocated successfully.\n");
        // Enter values into the allocated memory
        for (int i = 0; i < SIZE; i++) {
            ptr[i] = i;
        }
        printf("The values inserted into the dynamic memory are:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");

        // Free the dynamically allocated memory
        free(ptr);
        printf("Memory freed successfully.\n");
    }
    return 0;
}