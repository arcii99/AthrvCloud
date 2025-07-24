//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000000

void bubbleSort(int arr[], int size) {
    int temp;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    int arr[MAX_ARRAY_SIZE];
    for(int i=0; i<MAX_ARRAY_SIZE; i++){
        arr[i] = rand() % 1000; // random values between 0 to 999
    }

    start = clock(); // starting the timer
    bubbleSort(arr, MAX_ARRAY_SIZE); // sorting the array using bubble sort
    end = clock(); // stopping the timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of size %d is %f seconds.\n", MAX_ARRAY_SIZE, cpu_time_used);

    return 0;
}