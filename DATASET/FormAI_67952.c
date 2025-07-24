//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>

#define MAX_SIZE 10

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, j, temp, arr[MAX_SIZE] = {4, 6, 1, 8, 3, 9, 7, 2, 0, 5};

    printf("Unsorted Array:\n");
    printArray(arr, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                printf("Pass %d:\n", i+1);
                printArray(arr, MAX_SIZE);
            }
        }
    }

    printf("Sorted Array:\n");
    printArray(arr, MAX_SIZE);

    return 0;
}