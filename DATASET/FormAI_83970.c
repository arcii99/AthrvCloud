//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* This program demonstrates benchmarking in C, by comparing two different sorting algorithms.
The program generates random integers and sorts them using bubble sort and quick sort algorithms.
It then measures the time taken by both algorithms and prints out the results. */

void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void quick_sort(int *arr, int left, int right) {
    int i = left, j = right, pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

int main() {
    int n = 10000;
    int arr1[n], arr2[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 10001;
        arr2[i] = arr1[i];
    }

    printf("Sorting %d random integers...\n", n);
    clock_t t;

    t = clock();
    bubble_sort(arr1, n);
    t = clock() - t;
    printf("Bubble Sort took %f seconds.\n", ((double) t) / CLOCKS_PER_SEC);

    t = clock();
    quick_sort(arr2, 0, n - 1);
    t = clock() - t;
    printf("Quick Sort took %f seconds.\n", ((double) t) / CLOCKS_PER_SEC);

    return 0;
}