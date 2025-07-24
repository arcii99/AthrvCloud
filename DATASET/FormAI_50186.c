//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    clock_t start, end;
    double cpu_time_used;
    
    srand(time(NULL));  // seed for random number generation
    
    // filling the array with random numbers between 1 and 100
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    // code for bubble sort
    start = clock();  // start time
    int temp;
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = 0; j < SIZE - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();  // end time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // CPU time used
    printf("Time taken for bubble sort: %f seconds\n", cpu_time_used);
    
    // code for selection sort
    start = clock();  // start time
    int minIndex, minValue;
    for(int i = 0; i < SIZE - 1; i++) {
        minValue = arr[i];
        minIndex = i;
        for(int j = i+1; j < SIZE; j++) {
            if(arr[j] < minValue) {
                minValue = arr[j];
                minIndex = j;
            }
        }
        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    end = clock();  // end time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // CPU time used
    printf("Time taken for selection sort: %f seconds\n", cpu_time_used);
    
    // code for insertion sort
    start = clock();  // start time
    int j, key;
    for(int i = 1; i < SIZE; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    end = clock();  // end time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // CPU time used
    printf("Time taken for insertion sort: %f seconds\n", cpu_time_used);
    
    return 0;
}