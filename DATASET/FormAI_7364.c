//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 1000000

// A function to randomly generate an array of integers
void gen_array(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand() % ARR_LEN;
    }
}

// A function to print the array
void print_arr(int arr[]) {
    for (int i = 0; i < ARR_LEN; i++) {
        printf("%d ", arr[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
}

// A function to sort the array using Bubble Sort algorithm
void bubble_sort(int arr[]) {
    for (int i = 0; i < ARR_LEN - 1; i++) {
        for (int j = 0; j < ARR_LEN - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARR_LEN];

    // Generate an unsorted array
    gen_array(arr);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_arr(arr);

    // Sort the array using Bubble Sort algorithm
    clock_t t_start = clock();
    bubble_sort(arr);
    clock_t t_end = clock();

    // Calculate the time taken to sort the array
    double exec_time = (double)(t_end - t_start) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    print_arr(arr);

    // Print the execution time
    printf("Execution time: %f seconds\n", exec_time);

    return 0;
}