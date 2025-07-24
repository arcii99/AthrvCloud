//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < (size - 1); ++i) {
        for (j = 0; j < size - 1 - i; ++j) {
            if (array[j + 1] < array[j]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter number of elements in the array: ");
    scanf("%d", &size);
    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", array + i);
    }
    bubble_sort(array, size);
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(array + i));
    }
    free(array);
    return 0;
}