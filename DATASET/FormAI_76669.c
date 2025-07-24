//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[] = {5, 3, 7, 1, 9, 4, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("\nSorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        printf("\nArray after partition: ");
        for(int i=low; i<=high; i++) {
            printf("%d ", arr[i]);
        }

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low-1);

    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i+1);
}