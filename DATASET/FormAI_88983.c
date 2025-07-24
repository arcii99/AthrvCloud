//FormAI DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void quickSort(int* arr, int left, int right);

int main() {
    srand(time(NULL));
    int arr[ARRAY_SIZE];
    
    // initialize array with random values
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Unsorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, ARRAY_SIZE-1);
    
    printf("\n\nSorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void quickSort(int* arr, int left, int right) {
    if(left >= right) return;
    
    int pivot = arr[left];
    int i = left;
    int j = right;
    
    while(i < j) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        
        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
    
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}