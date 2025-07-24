//FormAI DATASET v1.0 Category: Benchmarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Romeo and Juliet Benchmarking program
// Written by a computer program that never sleeps

int main() {
    int num_data_points = 10000;
    int data[num_data_points];
    srand(time(NULL));

    // Romeo: Oh sweet Juliet, let us create an array of random integers
    for (int i = 0; i < num_data_points; i++) {
        data[i] = rand() % 100;
    }

    // Juliet: It doth warm my heart to see such randomness
    // Let us now sort the array in ascending order

    // Romeo: Indeed fair Juliet, let us use the bubble sort algorithm
    clock_t start = clock();
    for (int i = 0; i < num_data_points - 1; i++) {
        for (int j = 0; j < num_data_points - i - 1; j++) {
            if (data[j] > data[j+1]) {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Juliet: Such elegance in simplicity, Romeo. But can we not do better?
    // Let us try quick sort algorithm instead

    // Romeo: Ah, my lady, of course. A more efficient choice indeed.
    // Let us add a function to partition the array correctly for quick sort
    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] <= pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i+1];
            arr[i+1] = arr[high];
            arr[high] = temp;

            quicksort(arr, low, i);
            quicksort(arr, i+2, high);
        }
    }

    // Juliet: Such a clever algorithm, Romeo. Let us time it and see our glory
    start = clock();
    quicksort(data, 0, num_data_points - 1);
    end = clock();
    double time_taken_qsort = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Romeo: It seems our efforts have not gone in vain, fair Juliet.
    // Let us print the time taken by each algorithm and bask in our glory
    printf("Time taken by bubble sort: %f seconds\n", time_taken);
    printf("Time taken by quick sort: %f seconds\n", time_taken_qsort);

    return 0;
}