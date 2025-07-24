//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {17, 9, 3, 22, 28, 24, 20, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted Array: ");
    printArray(arr, size);
    
    bubbleSort(arr, size);
    
    printf("Sorted Array: ");
    printArray(arr, size);
    
    return 0;
}