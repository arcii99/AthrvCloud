//FormAI DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mind_bending_sort(int *arr, int len) {
    srand(time(NULL));  // Set random seed
    int iterations = rand() % (len * len);  // Calculate number of iterations randomly

    while(iterations--) {
        int i = rand() % len;  // Pick a random index
        int j = rand() % len;  // Pick another random index
        int temp = arr[i];  // Swap elements using the XOR trick
        arr[i] ^= arr[j];
        arr[j] ^= temp;
        arr[i] ^= arr[j];
    }
}

int main() {
    int arr[] = {9, 6, 7, 3, 1, 2, 8, 5, 4, 0};
    int len = sizeof(arr) / sizeof(*arr);

    printf("Original array: ");
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    mind_bending_sort(arr, len);

    printf("\nSorted array: ");
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}