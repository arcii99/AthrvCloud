//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int arr[10000]; // declare and initialize array
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start, end;
    double total_time;

    // linear search
    int target = 50;
    int index = -1;
    start = clock();
    for (int i = 0; i < 10000; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Linear search time: %f seconds\n", total_time);

    // bubble sort
    start = clock();
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 9999-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f seconds\n", total_time);

    return 0;
}