//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // 1 million

// Generate a random array of integers
void generate_random_array(int* arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }
}

// Bubble Sort
void bubble_sort(int* arr) {
    int temp;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function for benchmarking
int main() {
    int arr[ARRAY_SIZE];
    double bubble_sort_time; // Time taken by Bubble Sort
    clock_t start, end;

    // Generate the random array
    generate_random_array(arr);

    // Benchmarking Bubble Sort
    start = clock();
    bubble_sort(arr);
    end = clock();
    bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort: %.2lf seconds\n", bubble_sort_time);

    return 0;
}