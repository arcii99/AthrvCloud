//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

void *my_malloc(int size) {
    if (size <= 0) return NULL;
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) return;
    free(ptr);
    ptr = NULL;
}

int main() {
    int n = 5, m = 3;
    int **arr = (int **)my_malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)my_malloc(sizeof(int) * (m + i));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + i; j++) {
            arr[i][j] = i + j;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        my_free(arr[i]);
    }
    my_free(arr);
    return 0;
}