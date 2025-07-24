//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include<stdio.h>

void print_array(int arr[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i != length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertion_sort(int arr[], int length) {
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[5] = { 64, 25, 12, 22, 11 };
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_array(arr, length);

    printf("Sorting in progress...");
    insertion_sort(arr, length);

    printf("After sorting: ");
    print_array(arr, length);

    printf("Congratulations! Your numbers are now in ascending order. Stay organized and be grateful!\n");
    return 0;
}