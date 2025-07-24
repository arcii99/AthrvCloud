//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n){
  // Function to print the array
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    // Bubble Sort Logic
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }
}

int main(){
    // Taking input from user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    printArray(arr, n);

    // Sorting the array using Bubble Sort
    printf("\nBubble Sorting Process: \n");
    bubbleSort(arr, n);

    // Printing the sorted array
    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}