//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 100000000 // Number of elements in array

// Function to generate random numbers
int random_num() {
    return rand() % 1000;
}

// Function to swap two elements in an array
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort on an array
void bubble_sort(int arr[]) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[N];
    struct timeval start, end;
    double elapsed_time;

    // Generate random array
    for (int i = 0; i < N; i++) {
        arr[i] = random_num();
    }

    // Perform bubble sort and time it
    gettimeofday(&start, NULL);
    bubble_sort(arr);
    gettimeofday(&end, NULL);

    // Calculate elapsed time in milliseconds and print results
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;
    printf("Elapsed time: %.2f ms\n", elapsed_time);

    return 0;
}