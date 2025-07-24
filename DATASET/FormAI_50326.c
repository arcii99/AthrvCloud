//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void generateRandomArray(int arr[]) {
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

void printArray(int arr[]) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[]) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        for(int j=0; j<ARRAY_SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int randomArray[ARRAY_SIZE];
    double startTime, endTime, totalTime;

    generateRandomArray(randomArray);

    printf("Unsorted array: \n");
    printArray(randomArray);

    startTime = clock();
    bubbleSort(randomArray);
    endTime = clock();

    printf("Sorted array: \n");
    printArray(randomArray);

    totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds.\n", totalTime);

    return 0;
}