//FormAI DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
    int arr[] = {18, 22, 10, 9, 4, 7, 20, 27, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n-1);

    printf("After sorting: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for(int j=left; j<=right-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return i+1;
}