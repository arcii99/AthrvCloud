//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random numbers */
void generate_random_numbers(int* arr, int size) {
    srand(time(NULL));                          // seed the random number generator
    for(int i=0; i<size; i++) {
        arr[i] = rand() % 100;                  // generate a random number between 0 and 99
    }
}

/* Function to perform bubble sort */
void perform_bubble_sort(int* arr, int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int size = 10000;                            // array size
    int arr[size];                               // array to hold numbers
    clock_t start, end;
    double cpu_time_used;

    /* Generate random numbers */
    generate_random_numbers(arr, size);

    /* Perform Bubble Sort */
    start = clock();
    perform_bubble_sort(arr, size);
    end = clock();

    /* Calculate the CPU time used */
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /* Print the sorted array */
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    /* Print the CPU time used */
    printf("\n\nCPU Time Used: %lf seconds.", cpu_time_used);
    return 0;
}