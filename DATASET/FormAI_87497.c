//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int numAliens, numDays, prob; // declare integer variables to store user inputs and probability value
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of potential aliens in your area: ");
    scanf("%d", &numAliens);
    
    printf("Enter the number of days you think you have until the aliens arrive: ");
    scanf("%d", &numDays);
    
    prob = rand() % 101; // generate a random number between 0 and 100 to represent the probability of an invasion
    
    printf("\nCalculating...\n");
    printf("The probability of an alien invasion is %d%%\n", prob);
    
    if (prob <= 30) // If probability of an invasion is less than or equal to 30%
    {
        printf("You probably have nothing to worry about. Enjoy your day!\n");
    }
    else if (prob > 30 && prob <= 70) // If probability of an invasion is between 31% and 70%
    {
        if (numDays >= 7) // If user has at least 1 week until the possible invasion
        {
            printf("You have some time to prepare for a possible invasion.\n");
        }
        else // If user has less than 1 week until the possible invasion
        {
            printf("You don't have much time to prepare. Act fast!\n");
        }
    }
    else // If probability of an invasion is greater than 70%
    {
        printf("There's a high chance of an invasion. It's time to start gathering resources and preparing for battle!\n");
    }
    
    return 0; // End the program
}