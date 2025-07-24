//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define MAX_VALUE 10000

void quicksort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *a, int *b);

int main() {
    int arr[SIZE];
    srand(time(NULL));  // initialize random seed

    // generate random array of integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // sort array using quicksort algorithm
    quicksort(arr, 0, SIZE-1);

    // print sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex-1);
        quicksort(arr, pivotIndex+1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[right]);

    return i+1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}