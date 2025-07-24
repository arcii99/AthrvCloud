//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int arr[]) {
    for(int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[]) {
    for(int i=0; i<SIZE-1; i++) {
        for(int j=i+1; j<SIZE; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[]) {
    for(int i=1; i<SIZE; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[]) {
    for(int i=0; i<SIZE-1; i++) {
        for(int j=0; j<SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    srand(time(0));
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand()%100;
    }
    
    printf("Unsorted Array: ");
    printArray(arr);
    
    selectionSort(arr);
    printf("Selection Sorted Array: ");
    printArray(arr);
    
    insertionSort(arr);
    printf("Insertion Sorted Array: ");
    printArray(arr);
    
    bubbleSort(arr);
    printf("Bubble Sorted Array: ");
    printArray(arr);
    
    return 0;
}