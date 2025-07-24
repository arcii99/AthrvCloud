//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the random number generator!\n");
    srand(time(NULL)); // seeding random number generator with current time
    
    int num_random, num_range; // declare variables for number of random numbers and range
    
    // ask user for number of random numbers and range
    printf("How many random numbers would you like to generate? ");
    scanf("%d", &num_random);
    
    printf("What is the maximum range for the numbers? ");
    scanf("%d", &num_range);
    
    // generate and print random numbers
    printf("\nHere are %d random numbers between 0 and %d:\n", num_random, num_range);
    for (int i = 0; i < num_random; i++) {
        printf("%d ", rand() % num_range);
    }
    return 0;
}