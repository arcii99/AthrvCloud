//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS_SIZE 1000000

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }

    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    int numbers[NUMBERS_SIZE];
    int i;

    // Randomly generate numbers to sort
    srand(time(NULL));
    for (i = 0; i < NUMBERS_SIZE; i++) {
        numbers[i] = rand() % 1000;
    }

    // Bubble sort
    clock_t start_time = clock();
    bubbleSort(numbers, NUMBERS_SIZE);
    clock_t end_time = clock();
    double bubble_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Quick sort
    srand(time(NULL)); // Reset the seed to get the same numbers
    for (i = 0; i < NUMBERS_SIZE; i++) {
        numbers[i] = rand() % 1000;
    }
    start_time = clock();
    quickSort(numbers, 0, NUMBERS_SIZE - 1);
    end_time = clock();
    double quick_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print results
    printf("Bubble sort took %lf seconds.\n", bubble_sort_time);
    printf("Quick sort took %lf seconds.\n", quick_sort_time);

    return 0;
}