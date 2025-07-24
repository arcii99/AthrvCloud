//FormAI DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex, temp;
    for(int i=0; i<size-1; i++) {
        minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size) {
    int j, temp;
    for(int i=1; i<size; i++) {
        j = i-1;
        temp = arr[i];
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(0));
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    printf("Original Array: ");
    printArray(arr, ARRAY_SIZE);
    
    printf("\nBubble Sort: ");
    bubbleSort(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);
    
    printf("\nSelection Sort: ");
    selectionSort(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);
    
    printf("\nInsertion Sort: ");
    insertionSort(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);
    
    return 0;
}