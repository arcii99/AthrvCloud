//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 100000

void populate_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int *arr) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main(void) {
    // Populate array with random integers
    int array_to_sort[ARRAY_SIZE];
    populate_array(array_to_sort);

    // Display unsorted array
    printf("Unsorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_to_sort[i]);
    }

    // Measure time for bubble sort function
    clock_t start_bubble = clock();
    bubble_sort(array_to_sort);
    clock_t end_bubble = clock();

    // Measure time for merge sort function
    int array_to_sort_copy[ARRAY_SIZE];
    populate_array(array_to_sort_copy);
    clock_t start_merge = clock();
    merge_sort(array_to_sort_copy, 0, ARRAY_SIZE-1);
    clock_t end_merge = clock();

    // Display sorted array
    printf("\n\nSorted Array (Bubble Sort):\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_to_sort[i]);
    }

    printf("\n\nSorted Array (Merge Sort):\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_to_sort_copy[i]);
    }

    // Print running times
    printf("\n\nBubble Sort running time: %fs", (double)(end_bubble - start_bubble)/CLOCKS_PER_SEC);
    printf("\nMerge Sort running time: %fs", (double)(end_merge - start_merge)/CLOCKS_PER_SEC);

    return 0;
}