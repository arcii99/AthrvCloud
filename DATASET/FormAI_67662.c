//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // create an array of integers
    int arr[] = {7, 3, 9, 2, 4, 1, 5, 6, 8, 0};

    printf("Before sorting: ");
    print_array(arr, 10);

    // sort the array using bubble sort
    bubble_sort(arr, 10);

    printf("After sorting: ");
    print_array(arr, 10);

    return 0;
}