//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int array[] = {71, 32, 29, 77, 5, 75, 41, 15, 18, 13};
    int len = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);

    mergeSort(array, 0, len - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);

    return 0;
}