//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    printf("\nWelcome to the Random Number Generator\n");

    // Setting up the seed for random numbers
    srand(time(0));

    // Creating a loop to generate 10 random numbers
    for(int i=0; i<10; i++) {

        printf("\nRandom Number %d: %d", i+1, rand());
    }

    printf("\n\nThank You for using the Random Number Generator!");
    return 0;
}