//FormAI DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>

/* Function to print the elements of an array */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to merge the two halves of an array into a sorted array */
void merge(int arr[], int left, int mid, int right) {
    int temp[right-left+1];
    int i = left; // index of left subarray
    int j = mid+1; // index of right subarray
    int k = 0; // index of temporary array

    /* Merge the two subarrays */
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    /* Copy the remaining elements of left subarray */
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    /* Copy the remaining elements of right subarray */
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    /* Copy the sorted elements from temp back to arr */
    for (int p = 0; p < k; p++) {
        arr[left+p] = temp[p];
    }
}

/* Function to perform merge sort on an array */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        /* Recursive calls for left and right subarrays */
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        /* Merge the sorted subarrays */
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 7, 4, 8, 1, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size-1);

    printf("Sorted Array:\n");
    printArray(arr, size);

    return 0;
}