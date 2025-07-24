//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int left_size = middle - left + 1;
    int right_size = right - middle;

    int left_arr[left_size], right_arr[right_size];

    for (i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];

    for (j = 0; j < right_size; j++)
        right_arr[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main()
{
    // Generate an array of random integers
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // Time how long it takes to sort the array using merge sort
    clock_t start = clock();
    merge_sort(arr, 0, ARRAY_SIZE - 1);
    clock_t end = clock();

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken to sort %d integers: %f seconds\n", ARRAY_SIZE, time_taken);

    return 0;
}