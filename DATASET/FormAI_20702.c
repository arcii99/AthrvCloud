//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int arr[], int n) {
    printf("Array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int min, temp;
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[SIZE];
    srand(time(0));
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printArray(arr, SIZE);
    bubbleSort(arr, SIZE);
    printArray(arr, SIZE);
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);
    insertionSort(arr, SIZE);
    printArray(arr, SIZE);
    return 0;
}