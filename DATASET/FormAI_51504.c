//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int size = 100000000;
    int* arr = (int*)malloc(sizeof(int)*size);
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;

    // Initializing array with random values
    for(int i=0;i<size;i++)
    {
        arr[i] = rand()%1000;
    }

    // Naive approach to find sum of array elements
    start = clock();
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum of array using Naive approach is: %d\n",sum);
    printf("Time taken by Naive approach is: %f seconds\n\n", cpu_time_used);

    // Using OpenMP parallel construct
    start = clock();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<size;i++)
    {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum of array using OpenMP parallel construct is: %d\n",sum);
    printf("Time taken by OpenMP parallel construct is: %f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}