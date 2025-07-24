//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int arr[MAX_SIZE];

    // Generate random numbers for array
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Sorting Benchmark
    clock_t start = clock();

    // Bubble Sort
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        int flag = 0;
        for (int j = 0; j < MAX_SIZE - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    clock_t end = clock();
    double sorting_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", sorting_time);

    // Searching Benchmark
    start = clock();

    // Linear Search
    int search_value = rand() % MAX_SIZE;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (arr[i] == search_value) {
            printf("Value found at index %d\n", i);
            break;
        }
    }

    end = clock();
    double searching_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for searching: %f seconds\n", searching_time);

    return 0;
}