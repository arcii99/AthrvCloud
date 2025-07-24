//FormAI DATASET v1.0 Category: Random ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the C Random example program!\n");

    // Using the current time as seed value for the random number generator
    srand(time(NULL));

    // Declaring the variables
    int num1, num2, num3;
    float f1, f2, f3;

    // Generating random integers
    num1 = rand();
    num2 = rand();
    num3 = rand();

    // Generating random floating point numbers
    f1 = (float)rand()/(float)(RAND_MAX/100);
    f2 = (float)rand()/(float)(RAND_MAX/100);
    f3 = (float)rand()/(float)(RAND_MAX/100);

    // Displaying the random integers
    printf("Random Integer 1: %d\n", num1);
    printf("Random Integer 2: %d\n", num2);
    printf("Random Integer 3: %d\n", num3);

    // Displaying the random floating point numbers
    printf("Random Float 1: %f\n", f1);
    printf("Random Float 2: %f\n", f2);
    printf("Random Float 3: %f\n", f3);

    // Generating random integers within a given range
    int min = 10, max = 50;
    int range = max - min + 1;
    int randomNumInRange = (rand() % range) + min;
    printf("Random Integer within Range %d-%d: %d\n", min, max, randomNumInRange);

    printf("Thanks for running the C Random example program!\n");
    return 0;
}