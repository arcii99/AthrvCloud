//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Declare variables
    char input;
    int mbps;
    clock_t start, end;
    double time_used;

    // Welcome message
    printf("Welcome to the Internet Speed Test!\n");

    // Prompt user for input
    printf("Press 'S' to start the test: ");
    scanf("%c", &input);

    // Check for valid input
    if(input != 's' && input != 'S') {
        printf("Error: invalid input.\n");
        exit(1);
    }

    // Generate random mbps speed between 1-100
    srand(time(NULL));
    mbps = rand() % 100 + 1;

    // Start timer
    start = clock();

    // Simulate internet speed test by waiting for 5 seconds
    sleep(5);

    // End timer
    end = clock();

    // Calculate time taken for test
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print out results
    printf("Your internet speed is: %d mbps\n", mbps);
    printf("Time taken for test: %f seconds\n", time_used);

    return 0;
}