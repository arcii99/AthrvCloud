//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

// function to bubble sort an array in ascending order
void bubbleSort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[10] = { 5, 2, 9, 1, 7, 6, 3, 8, 4, 0 };
    printf("Unsorted Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubbleSort(array, 10);
    printf("Sorted Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}