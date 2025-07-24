//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000 // The size of array

// function to generate a random array of size SIZE
void generateRandomArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;
}

// function to bubble sort the array
void bubbleSort(int arr[]) {
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
    generateRandomArray(arr);

    // benchmarking the bubble sort function
    clock_t start_time = clock();
    bubbleSort(arr);
    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Bubble sort took %f seconds to execute.\n", execution_time);

    return 0;
}