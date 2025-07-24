//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000000

// Function to fill an array with random numbers
void fill_array(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the contents of an array
void print_array(int arr[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using bubble sort algorithm
void bubble_sort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random numbers and print them
    fill_array(arr);
    printf("Unsorted array:\n");
    print_array(arr);

    // Sort the array using bubble sort and print the sorted array
    printf("Sorting array...\n");
    bubble_sort(arr);
    printf("Sorted array:\n");
    print_array(arr);

    return 0;
}