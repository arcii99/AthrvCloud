//FormAI DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 3, 6, 2, 8, 5, 1, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}