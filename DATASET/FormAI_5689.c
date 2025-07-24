//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data_size = 10;
    int data[data_size];
    srand(time(NULL));
    printf("Original Array: ");
    for (int i = 0; i < data_size; i++) {
        data[i] = rand() % 100 + 1;
        printf("%d ", data[i]);
    }
    printf("\n\n");
    printf("Bubble Sort: ");
    bubbleSort(data, data_size);
    printArray(data, data_size);
    printf("\n");
    printf("Insertion Sort: ");
    insertionSort(data, data_size);
    printArray(data, data_size);
    return 0;
}