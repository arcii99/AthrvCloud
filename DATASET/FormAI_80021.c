//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void generateRandomIntegers(int arr[], int n){
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
}

int main()
{
    int arr[ARRAY_SIZE];
    generateRandomIntegers(arr, ARRAY_SIZE);

    clock_t start = clock();
    bubbleSort(arr, ARRAY_SIZE);
    clock_t end = clock();

    double timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", timeElapsed);
    return 0;
}