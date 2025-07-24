//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void fillArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double measureTime(int arr[], int size) {
    clock_t start, end;
    double time_taken;
    
    start = clock();
    // Perform sorting algorithm
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    end = clock();
    
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    int arr[MAX_SIZE];
    double time_taken;
    srand(time(0));
    
    for(int size = 10000; size <= MAX_SIZE; size *= 10) {
        fillArray(arr, size);
        
        printf("Array before sorting:\n");
        printArray(arr, size);
        
        time_taken = measureTime(arr, size);
        printf("Time taken for sorting %d elements: %f seconds\n", size, time_taken);
        
        printf("Array after sorting:\n");
        printArray(arr, size);
    }
    
    return 0;
}