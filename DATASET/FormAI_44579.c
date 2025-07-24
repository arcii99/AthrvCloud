//FormAI DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
    int arr[ARRAY_SIZE] = {8, 3, 1, 7, 4, 6, 5, 2, 9, 0};
    int i, j, temp;

    printf("---------- Before Sorting ----------\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort
    for (i = 0; i < ARRAY_SIZE-1; i++) {
        for (j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("---------- After Sorting ----------\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}