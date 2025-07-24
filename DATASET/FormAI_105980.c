//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform merge operation
void merge(int arr[], int low, int mid, int high) {
    int i, j, k, temp[high-low+1];
    i = low;
    j = mid+1;
    k = 0;

    // Merge elements from two arrays
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        } 
        else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    // Merge leftover elements
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    // Copy elements back to original array
    for (i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}

// Function to perform merge sort
void merge_sort(int arr[], int low, int high) {
    int mid;

    if (low < high) {
        // Find middle index
        mid = (low+high)/2;

        // Recursively sort first half
        merge_sort(arr, low, mid);

        // Recursively sort second half
        merge_sort(arr, mid+1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[10] = {23, 45, 12, 67, 89, 54, 30, 11, 88, 5};
    int i;

    printf("Before sorting: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Perform merge sort
    merge_sort(arr, 0, 9);

    printf("\nAfter sorting: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nOur love is like this sorting process,\n");
    printf("Sometimes we may be apart,\n");
    printf("But eventually we come back together,\n");
    printf("Stronger and better than before,\n");
    printf("Leaving behind all the chaos and mess,\n");
    printf("And emerging as a beautiful, sorted pair.\n");
    printf("I love you more than words can express,\n");
    printf("And like this sorting process, our love will endure forever.");

    return 0;
}