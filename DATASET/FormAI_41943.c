//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void fill_random(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int pivot = arr[right];
    int i = left, j = right;

    while (i < j) {
        while (i < j && arr[i] < pivot) i++;
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    arr[right] = arr[i];
    arr[i] = pivot;

    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main() {
    int arr[SIZE];
    fill_random(arr, SIZE);

    clock_t t1 = clock();
    bubble_sort(arr, SIZE);
    clock_t t2 = clock();
    printf("Bubble sort took %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    fill_random(arr, SIZE);

    t1 = clock();
    quick_sort(arr, 0, SIZE - 1);
    t2 = clock();
    printf("Quick sort took %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}