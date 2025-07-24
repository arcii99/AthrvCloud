//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

void **initialize_2d_array(int rows, int cols, int size) {
    void **arr = malloc(rows * sizeof(void *));
    if (arr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * size);
        if (arr[i] == NULL) {
            printf("Memory allocation failed!");
            exit(1);
        }
    }

    return arr;
}

void free_2d_array(void **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int rows = 3, cols = 4, size = sizeof(int);
    int **arr = (int **) initialize_2d_array(rows, cols, size);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * j;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free_2d_array((void **) arr, rows);
    return 0;
}