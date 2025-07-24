//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

void* myMalloc(size_t size) {
    void* ptr = malloc(size);
    if(!ptr) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("Allocated %zu bytes.\n", size);
    return ptr;
}

void* myCalloc(size_t n, size_t size) {
    void* ptr = calloc(n, size);
    if(!ptr) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("Allocated %zu bytes.\n", n*size);
    return ptr;
}

void* myRealloc(void* ptr, size_t size) {
    ptr = realloc(ptr, size);
    if(!ptr) {
        printf("Error reallocating memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("Reallocated to %zu bytes.\n", size);
    return ptr;
}

int main() {
    int* ptr1 = (int*)myMalloc(10*sizeof(int));
    int* ptr2 = (int*)myCalloc(5, sizeof(int));
    ptr1 = (int*)myRealloc(ptr1, 20*sizeof(int));
    free(ptr1);
    free(ptr2);
    return 0;
}