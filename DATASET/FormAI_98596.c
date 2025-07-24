//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Alien Invasion Probability Calculator\n");
    printf("-----------------------------------------------------\n");

    srand(time(NULL)); // Set the seed for the random number generator
    int alien_probability = rand() % 101; // Generate a random number between 0-100 to represent the probability of an alien invasion
    
    printf("Probability of an alien invasion: %d%%\n", alien_probability);
    
    if(alien_probability >= 90)
    {
        printf("ALERT! The probability of an alien invasion is extremely high!\n");
        printf("Please take necessary precautions such as stocking up on supplies and building a bunker.\n");
    }
    else if(alien_probability >= 50)
    {
        printf("The probability of an alien invasion is moderate.\n");
        printf("It might be a good idea to start thinking about a plan of action.\n");
    }
    else
    {
        printf("The probability of an alien invasion is low.\n");
        printf("You can relax and go about your daily life.\n");
    }

    return 0;
}