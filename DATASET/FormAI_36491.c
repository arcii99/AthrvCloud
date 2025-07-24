//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to print an integer array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for bubble sort
void bubbleSort(int arr[], int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function for selection sort
void selectionSort(int arr[], int size){
    int i, j, minIndex, temp;
    for (i = 0; i < size-1; i++){
        minIndex = i;
        for (j = i+1; j < size; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function for insertion sort
void insertionSort(int arr[], int size){
    int i, j, temp;
    for (i = 1; i < size; i++){
        temp = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    // Print original array
    printf("Original array: ");
    printArray(arr, size);
    
    // Perform bubble sort
    bubbleSort(arr, size);
    printf("After bubble sort: ");
    printArray(arr, size);
    
    // Perform selection sort
    selectionSort(arr, size);
    printf("After selection sort: ");
    printArray(arr, size);
    
    // Perform insertion sort
    insertionSort(arr, size);
    printf("After insertion sort: ");
    printArray(arr, size);
    
    return 0;
}