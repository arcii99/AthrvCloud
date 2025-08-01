//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int left_arr[n1], right_arr[n2];

    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 7, 1, 8, 3, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nOriginal Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}