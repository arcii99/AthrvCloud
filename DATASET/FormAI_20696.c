//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Original Array: ");
    print_array(arr, n);

    printf("Bubble Sort: ");
    clock_t start_bubble = clock();
    bubble_sort(arr, n);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    print_array(arr, n);
    printf("Bubble Sort time: %f seconds\n", time_bubble);

    printf("Selection Sort: ");
    clock_t start_selection = clock();
    selection_sort(arr, n);
    clock_t end_selection = clock();
    double time_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;
    print_array(arr, n);
    printf("Selection Sort time: %f seconds\n", time_selection);

    printf("Insertion Sort: ");
    clock_t start_insertion = clock();
    insertion_sort(arr, n);
    clock_t end_insertion = clock();
    double time_insertion = (double)(end_insertion - start_insertion) / CLOCKS_PER_SEC;
    print_array(arr, n);
    printf("Insertion Sort time: %f seconds\n", time_insertion);

    return 0;
}