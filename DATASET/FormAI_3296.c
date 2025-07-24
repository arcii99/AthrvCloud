//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void displayArray(int arr[], int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        displayArray(arr, size);
    }
}

int main(){
    int arr[SIZE];
    srand(time(0));
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }
    printf("Initial array: ");
    displayArray(arr, SIZE);
    printf("Sorting array using bubble sort...\n");
    bubbleSort(arr, SIZE);
    printf("Final array: ");
    displayArray(arr, SIZE);
    return 0;
}