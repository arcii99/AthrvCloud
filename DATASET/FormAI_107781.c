//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <time.h>

// Function to be benchmarked
void myFunction()
{
    // Do some heavy computation
    int result = 0;
    for (int i = 0; i < 1000000; i++)
    {
        result += i;
    }
}

int main()
{
    // Get the current clock time at the start of execution
    clock_t start_time = clock();

    // Call the function to be benchmarked
    myFunction();

    // Get the current clock time at the end of execution
    clock_t end_time = clock();

    // Calculate the execution time in seconds
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the execution time to the console
    printf("Execution Time: %f seconds\n", execution_time);

    return 0;
}