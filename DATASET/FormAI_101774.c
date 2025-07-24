//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000000
#define NUM_TRIALS 10000

void sort_quick(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, j;
    double avg_time = 0.0, total_time = 0.0;
    clock_t start, end;
    int arr[MAX_NUM];

    // Generate a random array of integers
    srand(time(NULL));
    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % MAX_NUM;
    }

    printf("Starting benchmark...\n");
    printf("Trials: %d \n", NUM_TRIALS);
    printf("Array size: %d \n", MAX_NUM);

    for (i = 0; i < NUM_TRIALS; i++) {
        int temp[MAX_NUM];
        for (j = 0; j < MAX_NUM; j++) {
            temp[j] = arr[j];
        }

        // measure the time taken to sort the array
        start = clock();
        sort_quick(temp, 0, MAX_NUM - 1);
        end = clock();

        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // calculate the average time taken to sort the array
    avg_time = total_time / NUM_TRIALS;

    printf("Benchmark complete.\n");
    printf("Average time taken: %lf seconds.\n", avg_time);

    return 0;
}

void sort_quick(int arr[], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        sort_quick(arr, left, index - 1);
        sort_quick(arr, index + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left - 1);
    int j;
    for (j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}