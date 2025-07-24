//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int size) {
    int i, j, min_index, temp;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void print_array(int arr[], int size) {
    int i;
    printf("[");
    for (i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}

int main() {
    int arr[MAX_SIZE] = {3, 5, 2, 6, 1, 9, 4, 8, 7, 0};
    printf("Original array:\n");
    print_array(arr, MAX_SIZE);

    bubble_sort(arr, MAX_SIZE);
    printf("Bubble sort:\n");
    print_array(arr, MAX_SIZE);

    int arr2[MAX_SIZE] = {3, 5, 2, 6, 1, 9, 4, 8, 7, 0};
    insertion_sort(arr2, MAX_SIZE);
    printf("Insertion sort:\n");
    print_array(arr2, MAX_SIZE);

    int arr3[MAX_SIZE] = {3, 5, 2, 6, 1, 9, 4, 8, 7, 0};
    selection_sort(arr3, MAX_SIZE);
    printf("Selection sort:\n");
    print_array(arr3, MAX_SIZE);

    return 0;
}