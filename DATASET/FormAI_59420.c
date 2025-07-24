//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Let's sort some numbers with an energetic C program!\n\n");

    // Generate array of random numbers
    srand(time(0));
    int arr[20];
    printf("Unsorted array: [");
    for (int i=0; i<20; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("]\n\n");

    // Bubble sort algorithm
    for (int i=0; i<19; i++) {
        for (int j=0; j<19-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: [");
    for (int i=0; i<20; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return 0;
}