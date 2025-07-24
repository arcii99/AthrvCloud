//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void insertion_sort(int arr[], int n);
void print_array(int arr[], int n);

int main(void) {
    int arr[ARRAY_SIZE];

    /* Initialize the random number generator */
    srand(time(NULL));

    /* Fill the array with random numbers */
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    /* Sort the array using insertion sort */
    insertion_sort(arr, ARRAY_SIZE);

    /* Print the sorted array */
    print_array(arr, ARRAY_SIZE);

    return 0;
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}