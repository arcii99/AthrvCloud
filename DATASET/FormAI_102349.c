//FormAI DATASET v1.0 Category: Benchmarking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Function to generate an array of random integers
void fillArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        arr[i] = rand() % 100;
    }
}

// Function to print an array
void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

// Bubble sort algorithm to be measured
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    // Initialize variables and arrays
    int n = 10000;
    int arr[n];
    struct timeval t1, t2;
    double elapsedTime;

    // Fill array with random integers
    fillArray(arr, n);

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Measure time taken by bubbleSort function
    gettimeofday(&t1, NULL);
    bubbleSort(arr, n);
    gettimeofday(&t2, NULL);

    // Print sorted array
    printf("\nSorted array:\n");
    printArray(arr, n);

    // Calculate and print elapsed time
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("\nTime taken: %f ms\n", elapsedTime);

    return 0;
}