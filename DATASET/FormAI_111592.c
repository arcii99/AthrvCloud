//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that generates a random array with values between 1 and 1000
void generateRandomArray(int* arr, int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        arr[i] = rand()%1000 + 1;
    }
}

// Function that sorts an array using bubble sort algorithm
void bubbleSort(int* arr, int size){
    int i, j, temp;
    for(i = 0; i < size-1; ++i){
        for(j = 0; j < size-i-1; ++j){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function that measures the time it takes to sort an array using bubble sort
double measureBubbleSortTime(int* arr, int size){
    clock_t start, end;
    double timeTaken;

    start = clock();
    bubbleSort(arr, size);
    end = clock();

    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    return timeTaken;
}

// Main function
int main(){
    int size = 10000;
    int arr[size];

    // Generate a random array
    generateRandomArray(arr, size);

    // Measure the time it takes to sort the array using bubble sort
    double timeTaken = measureBubbleSortTime(arr, size);

    printf("Time taken to sort %d elements using bubble sort algorithm: %lf seconds", size, timeTaken);

    return 0;
}