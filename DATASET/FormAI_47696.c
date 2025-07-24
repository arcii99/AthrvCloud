//FormAI DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void panic(const char *msg, int line) {
    fprintf(stderr, "PANIC at line %d: %s\n", line, msg);
    exit(1);
}

#define N 10

int main() {
    int *arr = malloc(N * sizeof(int));
    if (!arr) {
        panic("Failed to allocate memory", __LINE__);
    }

    for (int i = 0; i < N; i++) {
        arr[i] = i * 2;
    }

    printf("Initial array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *new_arr = realloc(arr, 2 * N * sizeof(int));
    if (!new_arr) {
        panic("Failed to reallocate memory", __LINE__);
    }

    arr = new_arr;

    for (int i = N; i < 2 * N; i++) {
        arr[i] = i * 2;
    }

    printf("Modified array: ");
    for (int i = 0; i < 2 * N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}