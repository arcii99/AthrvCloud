//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include<stdio.h>

/* The function merges two subarrays - [left, middle] and [middle+1, right] */
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    /* Create temporary arrays */
    int leftArr[n1], rightArr[n2];
    
    /* Copy data from main array to temporary arrays */
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }
    
    /* Merge the temporary arrays back into the main array */
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of leftArr[], if there are any */
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of rightArr[], if there are any */
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/* The main mergeSort function */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        /* Recursively sort left and right halves */
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        
        /* Merge the sorted halves */
        merge(arr, left, middle, right);
    }
}

/* The main function to test the implementation */
int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    /* Print the original array */
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
	/* Sort the array using Merge Sort */
    mergeSort(arr, 0, n-1);
    
    /* Print the sorted array */
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}