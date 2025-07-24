//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE];
    int i;
    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % SIZE;

    clock_t t; 
    t = clock(); 

    bubbleSort(arr, SIZE);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

    printf("Bubble Sort took %f seconds to execute with size %d\n", time_taken, SIZE);

    return 0;
}