//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max_probability = 100;
    int probability = 0;
    int counter = 0;
    char response;

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator.\n\n");
    printf("This program will generate a random probability between 1 and 100 for the likelihood of an alien invasion.\n");
    printf("You can then enter 'y' or 'n' to see if the invasion will occur.\n");
    printf("Let's begin!\n\n");

    do
    {
        // Generate a random probability
        probability = (rand() % max_probability) + 1;
        printf("The probability of an alien invasion is: %d\n", probability);

        // Check if the invasion will occur
        if (probability >= 50)
        {
            printf("The invasion will occur!\n");
        }
        else
        {
            printf("The invasion will not occur.\n");
        }

        printf("Would you like to generate another probability? (y/n)\n");
        scanf(" %c", &response);

        counter++; // Keep track of how many times the probability was generated

    } while (response == 'y' || response == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator.\n");
    printf("You generated a probability %d time(s). Goodbye!\n", counter);

    return 0;
}