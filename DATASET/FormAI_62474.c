//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int ARR_SIZE = 100000;
    int arr[ARR_SIZE];

    // Initialize array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Find the maximum number in the array
    clock_t start = clock();
    int max = arr[0];
    for (int i = 1; i < ARR_SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finding the maximum number took %f seconds\n", cpu_time_used);

    // Sort the array using bubble sort algorithm
    start = clock();
    for (int i = 0; i < ARR_SIZE - 1; i++) {
        for (int j = 0; j < ARR_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting the array took %f seconds\n", cpu_time_used);

    // Calculate the average of the array
    start = clock();
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        sum += arr[i];
    }
    double average = (double) sum / ARR_SIZE;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Calculating the average of the array took %f seconds\n", cpu_time_used);

    printf("The maximum number in the array is %d\n", max);
    printf("The average of the array is %f\n", average);

    return 0;
}