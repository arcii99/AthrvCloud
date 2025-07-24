//FormAI DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int random_array[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // generate random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_array[i] = rand() % 1000;
    }

    // bubble sorting
    start = clock();
    int temp, i, j;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (random_array[i] > random_array[j]) {
                temp = random_array[i];
                random_array[i] = random_array[j];
                random_array[j] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %lf seconds\n", cpu_time_used);

    // quick sorting
    start = clock();
    void quicksort(int arr[], int low, int high);
    quicksort(random_array, 0, ARRAY_SIZE - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by quick sort: %lf seconds\n", cpu_time_used);

    return 0;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}