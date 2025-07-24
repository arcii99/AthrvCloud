//FormAI DATASET v1.0 Category: Random ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hello there! I'm going to generate a list of random numbers between 1 and 100!\n\n");

    srand(time(NULL)); // initialize the random number generator with the current time

    int num;

    // generate 50 random numbers and print them out
    for(int i = 1; i <= 50; i++)
    {
        num = rand() % 100 + 1; // generate a random number between 1 and 100
        printf("Random number %d: %d\n", i, num); // print out the random number
    }

    printf("\nTa-da! Hope you liked my random number generator! Bye for now!\n");

    return 0;
}