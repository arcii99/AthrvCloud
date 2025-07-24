//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {23, 12, 56, -7, 84, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("Sorted Array (Bubble Sort): ");
    printArray(arr, n);

    int arr2[] = {23, 12, 56, -7, 84, 90};
    
    selectionSort(arr2, n);    
    printf("Sorted Array (Selection Sort): ");
    printArray(arr2, n);

    int arr3[] = {23, 12, 56, -7, 84, 90};
    
    insertionSort(arr3, n);
    printf("Sorted Array (Insertion Sort): ");
    printArray(arr3, n);

    return 0;
}