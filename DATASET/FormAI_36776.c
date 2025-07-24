//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>

// Energetic Sorting Example Program

int main() {
    printf("Let's sort some numbers with amazing speed!\n");

    int arr[10] = {8, 4, 9, 2, 10, 3, 6, 1, 5, 7};
    int n = 10;

    printf("Unsorted Array: {");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("}\n");

    // Let's sort the array with the most high-energy sorting algorithm: Quick Sort!
    // First, we need a partition function to divide the array into two parts
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    // Now, let's use the partition function to recursively sort the array with quick sort
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: {");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("}\n");

    printf("Done sorting! That was fast and energetic!\n");

    return 0;
}