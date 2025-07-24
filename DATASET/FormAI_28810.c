//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void memory_alloc(int **arr, int size) {
    if (size <= 0) {
        return;
    }
    *arr = (int *) malloc(size * sizeof(int));
    if (*arr == NULL) {
        printf("Error! Memory not allocated.");
        return;
    }
    else {
        printf("Memory allocated successfully.\n");
        memory_alloc(arr + 1, size - 1);
    }
}

int main() {
    int *arr = NULL;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    memory_alloc(&arr, size);

    printf("The memory was allocated and the addresses are:\n");

    for (int i = 0; i < size; i++) {
        printf("%d address: %p\n", i + 1, arr + i);
    }

    free(arr); // free memory

    return 0;
}