//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("Array after pass %d: ", i+1);
        printArray(arr, size);
    }
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        printf("Array after pass %d: ", i+1);
        printArray(arr, size);
    }
}

void insertionSort(int arr[], int size){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;

        printf("Array after pass %d: ", i);
        printArray(arr, size);
    }
}

int main(){
    int arr[] = {5, 8, 1, 3, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, size);

    printf("\nBubble Sort:\n");
    bubbleSort(arr, size);

    int arr2[] = {5, 8, 1, 3, 9, 6};
    printf("\nSelection Sort:\n");
    selectionSort(arr2, size);

    int arr3[] = {5, 8, 1, 3, 9, 6};
    printf("\nInsertion Sort:\n");
    insertionSort(arr3, size);

    return 0;
}