//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate random numbers
void generateRandomNumbers(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }
}

// Function to print the array
void printArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array
void bubbleSort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    generateRandomNumbers(arr);
    printf("Original Array:\n");
    printArray(arr);
    bubbleSort(arr);
    printf("Sorted Array:\n");
    printArray(arr);
    return 0;
}