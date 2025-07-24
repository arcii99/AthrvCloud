//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void dynamic_array_add(int **arr, int *size, int element) {
    (*size)++;
    int *temp = (int*) realloc(*arr, *size * sizeof(int));
    if (temp == NULL) {
        printf("Error: Could not allocate memory!\n");
        free(*arr);
        exit(1);
    }
    *arr = temp;
    (*arr)[(*size)-1] = element;
}

int main() {
    int size = 0;
    int *arr = NULL;
    
    dynamic_array_add(&arr, &size, 10);
    dynamic_array_add(&arr, &size, 20);
    dynamic_array_add(&arr, &size, 30);
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}