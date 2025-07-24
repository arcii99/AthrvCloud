//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void randomizedArray(int arr[], int n){
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++){
        arr[i] = rand() % n;
    } 
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double getExecutionTime(clock_t start, clock_t end){
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main(){
    int array[ARRAY_SIZE];
    double timeTaken;
    randomizedArray(array, ARRAY_SIZE);
    printf("Unsorted Array: ");
    // printArray(array, ARRAY_SIZE);
    clock_t start = clock();
    bubbleSort(array, ARRAY_SIZE);
    clock_t end = clock();
    printf("Sorted Array: ");
    // printArray(array, ARRAY_SIZE);
    timeTaken = getExecutionTime(start, end);
    printf("Execution Time: %f seconds\n", timeTaken);
    return 0;
}