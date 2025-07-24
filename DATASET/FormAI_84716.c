//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Seed the random number generator.
    srand(time(NULL));

    // Fill the array with random numbers.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Print the unsorted array.
    printf("Unsorted Array:\n");
    print_array(arr, ARRAY_SIZE);

    // Sort the array using bubble sort.
    bubble_sort(arr, ARRAY_SIZE);

    // Print the sorted array.
    printf("Sorted Array:\n");
    print_array(arr, ARRAY_SIZE);

    return 0;
}