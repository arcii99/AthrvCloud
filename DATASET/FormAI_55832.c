//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int arr[], int size){
    printf("[ ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i = low-1;
        for(int j=low; j<high; j++){
            if(arr[j] < pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[high]);
        int pi = i+1;
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    srand(time(NULL));
    int size = 10;
    int arr[size];
    printf("Original array: ");
    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }
    display(arr, size);
    
    printf("\nUsing Bubble Sort: ");
    bubbleSort(arr, size);
    display(arr, size);
    
    printf("\nUsing Quick Sort: ");
    quickSort(arr, 0, size-1);
    display(arr, size);
    
    return 0;
}