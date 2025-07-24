//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL)); // Set the seed for the random number generator
    
    char question[100]; // Define an array to hold the user's question
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me a yes or no question and I will provide an answer!\n");
    
    while (1)
    {
        printf("\nEnter your question (or type 'quit' to exit): ");
        fgets(question, 100, stdin); // Get the user's question
        
        if (strcmp(question, "quit\n") == 0) // Check if the user wants to quit
        {
            printf("Thanks for playing. Goodbye!\n");
            break;
        }
        
        int answer = rand() % 2; // Generate a random number between 0 and 1
        
        if (answer == 0)
        {
            printf("\nHmm, my sources say no.\n");
        }
        else
        {
            printf("\nAbsolutely, yes!\n");
        }
    }
    
    return 0;
}