//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void allocate(int **ptr, int size) {
    *ptr = (int*)malloc(size * sizeof(int));
    if (*ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
}

void initialize(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        ptr[i] = i;
    }
}

void print(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void deallocate(int **ptr) {
    free(*ptr);
    *ptr = NULL;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = NULL;
    allocate(&arr, size);
    initialize(arr, size);
    printf("Array: ");
    print(arr, size);
    deallocate(&arr);

    return 0;
}