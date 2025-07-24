//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>

void quicksort(int arr[], int left, int right);

int main() {
    int arr[] = {5, 2, 4, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quicksort(int arr[], int left, int right) {
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = arr[left];

    while (left < right) {
        while ((arr[right] >= pivot) && (left < right)) {
            right--;
        }
        if (left != right) {
            arr[left] = arr[right];
            left++;
        }
        while ((arr[left] <= pivot) && (left < right)) {
            left++;
        }
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) {
        quicksort(arr, left, pivot-1);
    }
    if (right > pivot) {
        quicksort(arr, pivot+1, right);
    }
}