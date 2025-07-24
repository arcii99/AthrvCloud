//FormAI DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>

#define ARRAY_SIZE 10

int main(void) {
    int arr[ARRAY_SIZE] = { 9, 2, 7, 5, 3, 6, 1, 4, 8, 0 };
    int i, j, temp;

    printf("Unsorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    for(i = 0; i < ARRAY_SIZE; i++) {
        for(j = i+1; j < ARRAY_SIZE; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}