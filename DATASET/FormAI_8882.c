//FormAI DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    printf("Sorting array using bubble sort method \n");
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}