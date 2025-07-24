//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void quick_sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int* a, int* b);

int main() {
    int arr[SIZE];
    int i;

    srand(time(NULL));

    // Generate random array
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort array using quick sort algorithm
    quick_sort(arr, 0, SIZE - 1);

    // Print sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quick_sort(int arr[], int start, int end) {
    if (start < end) {
        int p_index = partition(arr, start, end);
        quick_sort(arr, start, p_index - 1);
        quick_sort(arr, p_index + 1, end);
    }
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    int j;

    for (j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return i + 1;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}