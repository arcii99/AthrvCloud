//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int arr[], int n) {
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

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (arr[i] <= pivot && i <= high) {
                i++;
            }
            while (arr[j] > pivot && j >= low) {
                j--;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i;
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100000;
    }
    clock_t start, end;
    double bubble_sort_time, quick_sort_time;
    start = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end = clock();
    bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds.\n", bubble_sort_time);
    start = clock();
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    quick_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %f seconds.\n", quick_sort_time);
    return 0;
}