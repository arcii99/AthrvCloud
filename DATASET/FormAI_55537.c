//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_VALUE 10000

void fill_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE + 1;
    }
}

long long int sum_array(int array[], int size) {
    long long int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);

    clock_t start_time, end_time;

    start_time = clock();
    long long int sum = sum_array(array, ARRAY_SIZE);
    end_time = clock();
    printf("Sum of the array: %lld\n", sum);
    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    fill_array(array, ARRAY_SIZE);

    start_time = clock();
    bubble_sort(array, ARRAY_SIZE);
    end_time = clock();
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}