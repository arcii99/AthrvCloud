//FormAI DATASET v1.0 Category: Random ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A program that generates random numbers in a peaceful way

int main(void) {
    // Set up the seed for random number generator
    srand(time(NULL));
    
    // Print a peaceful message
    printf("Let's generate some random numbers in a peaceful way...\n");
    
    // Set a counter variable to keep track of the loop
    int count = 1;
    
    // Loop through and generate 50 random numbers
    while (count <= 50) {
        // Generate a random number within the range of 0 to 99
        int random_number = rand() % 100;
        
        // Print the random number in a peaceful way
        printf("You are peaceful like a bird, and the number %d is like a peaceful tree.\n", random_number);
        
        // Increase the counter
        count++;
    }
    
    // Print a final peaceful message
    printf("We have generated 50 peaceful random numbers. May peace be with you!\n");
    
    return 0;
}