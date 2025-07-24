//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    printf("\nMemory freed successfully\n");

    return 0;
}