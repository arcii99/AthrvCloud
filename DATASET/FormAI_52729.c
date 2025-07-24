//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main()
{
    int arr[SIZE];
    int i,j,temp;

    clock_t start, end;

    srand(time(NULL));

    // filling the array with random integers
    for(i=0; i<SIZE; i++)
        arr[i] = rand() % 1000;

    printf("Starting benchmarking...\n\n");

    // Bubble Sort benchmarking
    start = clock();
    for(i=0; i<SIZE-1; i++)
        for(j=0; j<SIZE-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    end = clock();
    printf("Bubble Sort took %lf seconds to execute.\n", (double)(end - start)/CLOCKS_PER_SEC);

    // Selection Sort benchmarking
    for(i=0; i<SIZE; i++)
        arr[i] = rand() % 1000; // refill the array with random integers

    start = clock();
    for(i=0; i<SIZE-1; i++)
    {
        int min_idx = i;
        for(j=i+1; j<SIZE; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    end = clock();
    printf("Selection Sort took %lf seconds to execute.\n", (double)(end - start)/CLOCKS_PER_SEC);

    // Insertion Sort benchmarking
    for(i=0; i<SIZE; i++)
        arr[i] = rand() % 1000; // refill the array with random integers

    start = clock();
    for(i=1; i<SIZE; i++)
    {
        temp = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    end = clock();
    printf("Insertion Sort took %lf seconds to execute.\n", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}