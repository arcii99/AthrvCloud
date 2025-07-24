//FormAI DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

/* Custom secure sorting function */
void secure_sort(int* arr, int n) {
    int i, j, temp;
    /* Bubble sort algorithm */
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            /* Check if adjacent elements need to be swapped */
            if (arr[j] > arr[j+1]) {
                /* Swap the elements */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Main function */
int main() {
    int i, arr[ARRAY_SIZE];
    /* Fill array with random numbers */
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Sort the array */
    secure_sort(arr, ARRAY_SIZE);

    /* Print sorted array */
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}