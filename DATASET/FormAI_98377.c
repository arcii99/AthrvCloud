//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>

//User-defined function to swap two numbers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Function to implement Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {       
        // Last i elements are already in place   
        for (j = 0; j < n - i - 1; j++) {
            //check if adjacent element is greater or not
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    bubbleSort(arr, n); //Sorting Array using Bubble Sort
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}