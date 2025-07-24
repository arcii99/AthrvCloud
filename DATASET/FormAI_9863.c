//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int i;
    int arr[SIZE];
    srand(time(NULL));

    printf("Generating random numbers...\n");

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    printf("Finished generating random numbers\n");

    clock_t start = clock();
    bubble_sort(arr, SIZE);
    clock_t end = clock();

    double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble sort took %lf seconds to execute\n", bubble_time);

    start = clock();
    selection_sort(arr, SIZE);
    end = clock();

    double selection_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Selection sort took %lf seconds to execute\n", selection_time);

    if (bubble_time < selection_time) {
        printf("Bubble sort was faster than selection sort\n");
    } else {
        printf("Selection sort was faster than bubble sort\n");
    }

    return 0;
}