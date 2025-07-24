//FormAI DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>

//Function to swap two integers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Driver code to test above functions
int main() {
    int arr[] = {53, 12, 67, 5, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("After sorting: ");
    printArray(arr, n);
    return 0;
}