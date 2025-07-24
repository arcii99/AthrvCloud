//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n;
    double rand_num;

    // Seed the random number generator
    srand(time(0));

    // Prompt user for the number of random numbers to generate
    printf("How many random numbers do you want to generate? ");
    scanf("%d", &n);

    // Generate and print the random numbers
    printf("Here are your %d random numbers:\n", n);
    for(i=0; i<n; i++) {
        rand_num = ((double) rand() / (RAND_MAX)) * 1000; // Generate a random number between 0 and 1000
        printf("%.2f\n", rand_num);
    }

    return 0;
}