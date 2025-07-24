//FormAI DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5000000

// Function to check if array is sorted in ascending order
int is_sorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to shuffle array randomly
void shuffle(int arr[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }
    shuffle(arr, ARRAY_SIZE);

    clock_t start = clock();

    // Insertion Sort
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (is_sorted(arr, ARRAY_SIZE)) {
        printf("Array of size %d sorted successfully in %f seconds.\n", ARRAY_SIZE, time_taken);
    }
    else {
        printf("Error: Array of size %d was not sorted successfully.\n", ARRAY_SIZE);
    }

    return 0;
}