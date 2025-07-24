//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original unsorted array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array using bubble sort: \n");
    printArray(arr, n);
    printf("Don't you just love seeing an array get sorted? Me too! Keep coding, my friend!");
    return 0;
}