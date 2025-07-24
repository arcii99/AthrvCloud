//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000
#define MAX_ELEMENT_VALUE 1000

void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void generate_random_array(int arr[], int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_ELEMENT_VALUE + 1;
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int n = 10000;
    double time_taken;
    clock_t start, end;

    generate_random_array(arr, n);

    printf("Before sorting:\n");
    print_array(arr, n);

    start = clock();
    selection_sort(arr, n);
    end = clock();

    printf("After sorting:\n");
    print_array(arr, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements using selection sort: %f seconds\n", n, time_taken);

    return 0;
}