//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random generator with current time
    int arr[1000], sum = 0, i;

    // populate the array with random integers between 0 and 1000
    for (i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }

    // measure the time it takes to calculate the sum of the array elements
    clock_t start_time = clock();
    for (i = 0; i < 1000; i++) {
        sum += arr[i];
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // print the sum and the elapsed time
    printf("The sum of the array elements is: %d\n", sum);
    printf("Time taken to calculate the sum: %f seconds\n", elapsed_time);

    return 0;
}