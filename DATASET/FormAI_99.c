//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int arr[SIZE];

void generateRandomNumbers() {
    srand(time(NULL));
    for(int i=0;i<SIZE;i++) {
        arr[i] = rand() % SIZE + 1;
    }
}

void selectionSort() {
    int minIndex;
    for(int i=0;i<SIZE-1;i++) {
        minIndex = i;
        for(int j=i+1;j<SIZE;j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    clock_t t1,t2;
    double timeTaken;
    generateRandomNumbers();
    t1 = clock();
    selectionSort();
    t2 = clock();
    timeTaken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Time taken by Selection Sort: %f seconds\n", timeTaken);
    return 0;
}