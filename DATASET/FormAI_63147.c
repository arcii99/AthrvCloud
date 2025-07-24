//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10000

//Function to generate random numbers
void generateRandomNumbers(int* arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

//Function to swap elements of an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform bubble sort on an array
void bubbleSort(int* arr, int size) {
    int i, j;
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    generateRandomNumbers(arr, ARRAY_SIZE);

    //Benchmarking bubble sort
    printf("Benchmarking Bubble Sort...\n");

    clock_t begin = clock(); //Start time in clock cycles

    bubbleSort(arr, ARRAY_SIZE);

    clock_t end = clock(); //End time in clock cycles

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //Calculate time spent in seconds

    printf("\nBubble Sort Completed in %.6f Seconds\n", time_spent);

    return 0;
}