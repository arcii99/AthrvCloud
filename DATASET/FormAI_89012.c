//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int arr[10000], i;
    for (i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start = clock();
    bubbleSort(arr, 10000);
    clock_t end = clock();

    double time_taken = (end - start) / ((double) CLOCKS_PER_SEC);

    printf("Bubble sort took %f seconds to execute \n", time_taken);

    return 0;
}