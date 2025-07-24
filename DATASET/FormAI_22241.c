//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include<stdio.h>
#include<time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE], i;
    clock_t start_t, end_t;

    // Generating Random Numbers for Sorting
    srand((unsigned)time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100000;
    }

    // Benchmarking the Bubble Sort Algorithm
    start_t = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end_t = clock();

    double total_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("Bubble Sort Time Taken: %lf seconds", total_t);
    return 0;
}