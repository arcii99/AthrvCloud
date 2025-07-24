//FormAI DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Function to swap values in an array */
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to perform quick sort */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Main function */
int main() {
    int arr[] = {9, 10, 7, 4, 2, 1, 3, 8, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}