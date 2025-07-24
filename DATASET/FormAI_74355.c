//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to initialize the array with random integers
void initArray(int* arr, int size){
    srand(time(NULL)); // seed the random number generator with current time
    for(int i=0; i<size; i++){
        arr[i] = rand() % 100; // set random number between 0 and 99
    }
}

// Function to perform selection sort
void selectionSort(int* arr, int size){
    int minIndex, temp;
    for(int i=0; i<size-1; i++){
        minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // swap elements at i and minIndex
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    const int SIZE = 100000;
    int arr[SIZE];

    // initialize array with random integers
    initArray(arr, SIZE);

    printf("Array before sorting:\n");
    for(int i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // perform selection sort
    clock_t start = clock();
    selectionSort(arr, SIZE);
    clock_t end = clock();

    printf("Array after sorting:\n");
    for(int i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // print time taken for sorting
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection sort took %f seconds.\n", time_taken);

    return 0;
}