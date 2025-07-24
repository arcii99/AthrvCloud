//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));      // Seed random number generator

    int size = 100000;       // Array size
    int arr[size];

    //Populate array with random numbers between 0-9999
    for(int i = 0; i < size; i++) {      
        arr[i] = rand() % 10000;    
    }
    
    // Bubble Sort Algorithm
    clock_t start = clock();
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    float seconds = ((float) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort to execute: %f seconds", seconds);

    return 0;
}