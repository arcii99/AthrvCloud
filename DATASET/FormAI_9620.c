//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void randomizeArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        arr[i] = rand() % size;
    }
}

void bubbleSort(int arr[], int size){
    int i, j, temp;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int left, int right){
    int i, j, pivot, temp;
    if(left < right){
        pivot = left;
        i = left;
        j = right;
        while(i < j){
            while(arr[i] <= arr[pivot] && i < right){
                i++;
            }
            while(arr[j] > arr[pivot]){
                j--;
            }
            if(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}

int main(){
    int bubbleArray[ARRAY_SIZE];
    int quickArray[ARRAY_SIZE];
    int i;
    clock_t start, end;
    double timeTaken;

    randomizeArray(bubbleArray, ARRAY_SIZE);
    randomizeArray(quickArray, ARRAY_SIZE);

    start = clock();
    bubbleSort(bubbleArray, ARRAY_SIZE);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f seconds\n", timeTaken);

    start = clock();
    quickSort(quickArray, 0, ARRAY_SIZE - 1);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %f seconds\n", timeTaken);
    
    return 0;
}