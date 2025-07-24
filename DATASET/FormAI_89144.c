//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>

// Define constant variables
#define SIZE 10

// Define function to print array before and after sorting
void printArray(int arr[]) {
    printf("Array before sorting:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Array after sorting:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declare and initialize array with random integers
    int arr[SIZE] = {8, 3, 7, 2, 5, 4, 9, 10, 1, 6};

    // Print unsorted array
    printArray(arr);

    // Sort the array using bubble sort
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printArray(arr);

    return 0;
}