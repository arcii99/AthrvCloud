//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

// function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 18, 3, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    bubbleSort(arr, n);

    printf("\nArray after sorting:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    return 0;
}