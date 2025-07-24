//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the array

void printArray(int arr[], int arrSize){
    printf("[ ");
    for(int i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[SIZE];
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Populate array with random values
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }
    
    printf("Original Array:\n");
    printArray(arr, SIZE);
    
    quickSort(arr, 0, SIZE-1);
    
    printf("Sorted Array:\n");
    printArray(arr, SIZE);
    
    return 0;
}