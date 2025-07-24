//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

typedef struct {
    int firstNum, secondNum;
} NumPair;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int arr[]) {
    int i;
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, arr[ARRAY_SIZE];
    NumPair pair[ARRAY_SIZE];
    srand(time(NULL));
    
    // Randomly generate array elements
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    // Pairing the array elements in adjacent pairs
    for(i = 0; i < ARRAY_SIZE-1; i+=2) {
        pair[i].firstNum = arr[i];
        pair[i].secondNum = arr[i+1];
    }
    
    printf("Original Array: ");
    printArray(arr);
    
    // Sorting the adjacent pairs based on the second number in the pair
    bubbleSort((int *)(&pair), ARRAY_SIZE/2);
    
    // Rebuilding the sorted array from the pairs
    for(i = 0; i < ARRAY_SIZE-1; i+=2) {
        arr[i] = pair[i/2].firstNum;
        arr[i+1] = pair[i/2].secondNum;
    }
    
    printf("Sorted Array: ");
    printArray(arr);
    
    return 0;
}