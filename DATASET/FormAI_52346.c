//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main()
{
    int arr[N];
    
    // Fill the array with random integers
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    // Run the benchmarking test
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        // Loop through the array and do some calculation
        int sum = 0;
        for (int j = 0; j < i+1; j++)
        {
            sum += arr[j];
        }
    }
    clock_t end = clock();
    
    printf("Time taken: %ldms\n", (end-start)*1000/CLOCKS_PER_SEC);
    
    return 0;
}