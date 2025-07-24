//FormAI DATASET v1.0 Category: Random ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int lower;
int upper;
int num_of_randoms;

// Function to generate random numbers
void generateRandomNumbers()
{
    int i, num;
    
    // Generate num_of_randoms random numbers in the given range
    for(i = 1; i <= num_of_randoms; i++){
        num = (rand() % (upper - lower + 1)) + lower; // Formula to generate random number within given range
        printf("%d\n", num); // Print the generated random number
    }
}

// Main function
int main()
{
    // Initialize the seed with current time
    srand(time(NULL));
    
    // Get user input for lower bound, upper bound and number of randoms
    printf("Enter lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter upper bound of the range: ");
    scanf("%d", &upper);
    printf("Enter number of random numbers to generate: ");
    scanf("%d", &num_of_randoms);
    
    // Generate and print random numbers
    generateRandomNumbers();
    
    return 0;
}