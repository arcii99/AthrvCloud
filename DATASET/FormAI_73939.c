//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// function to allocate memory dynamically
void allocate_memory(int **arr, int n) {
    *arr = (int*) malloc(n * sizeof(int));
}

// function to Deallocate memory
void deallocate_memory(int *arr) {
    free(arr);
}

int main() {
    int n = 5;
    int *arr;

    // allocate memory
    allocate_memory(&arr, n);

    // assign values
    for(int i=0; i<n; i++) {
        arr[i] = i+1;
    }

    // print values
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // deallocate memory
    deallocate_memory(arr);

    return 0;
}