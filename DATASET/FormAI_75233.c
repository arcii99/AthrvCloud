//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// This program generates random numbers until a certain condition is met
// If the number generated is negative, the program crashes and restarts

int main()
{
    int num;    // Initialize a variable to store the generated number
    int count = 0;  // Initialize a counter variable
    
    while (1)   // Infinite loop to keep generating numbers until condition is met
    {
        num = rand();   // Generate a random number
        
        printf("Number generated: %d\n", num);   // Print the generated number
        
        if (num < 0)    // If number is negative, raise an error
        {
            fprintf(stderr, "Error: Negative number generated!\n");
            exit(1);    // Exit the program with an error code of 1
        }
        
        count++;    // Increment the counter
        
        if (count >= 10 && num%2 == 0) // If counter reaches 10 and number is even, break the loop
        {
            printf("Condition met!\n");
            break;
        }
    }
    
    printf("Program executed successfully!\n");  // Print success message
    
    return 0;
}