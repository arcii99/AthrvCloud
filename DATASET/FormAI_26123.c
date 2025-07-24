//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void print(int array[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertSort(int array[], int size) {
    int i, j, key;
    for (i = 1; i < size; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}

int main() {
    int size, i, cap;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid input.\n");
        exit(1);
    }
    int *array = malloc(size * sizeof(int));
    for (i = 0; i < size; ++i) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Unsorted array:\n");
    print(array, size);
    insertSort(array, size);
    printf("Sorted array:\n");
    print(array, size);
    free(array);
    return 0;
}