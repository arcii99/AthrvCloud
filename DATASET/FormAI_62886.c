//FormAI DATASET v1.0 Category: System boot optimizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Start timer
    clock_t start = clock();

    // Your boot optimizer code goes here
    
    // Generate random number of seconds between 1 and 5
    srand(time(NULL));
    int seconds = rand() % 5 + 1;

    // Delay execution for random number of seconds
    clock_t delay;
    delay = seconds * CLOCKS_PER_SEC;
    while (clock() < start + delay);

    // End timer and calculate execution time
    clock_t end = clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Boot optimization completed in %f seconds\n", execution_time);
    
    return 0;
}