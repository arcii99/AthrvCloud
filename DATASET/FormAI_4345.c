//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));   // Seed for random number generator
    int probability = rand() % 101;   // Generate a random number between 0 and 100 for probability calculation

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("The probability of an alien invasion today is %d%%\n", probability);

    if (probability < 30)
    {
        printf("Looks like we're safe for now.\n");
    }
    else if (probability >= 30 && probability < 60)
    {
        printf("We should start preparing just in case.\n");
    }
    else if (probability >= 60 && probability < 90)
    {
        printf("It's highly likely that we'll be invaded today. Take shelter immediately!\n");
    }
    else
    {
        printf("The aliens are definitely coming. It's time to fight for our survival!\n");
    }
    
    return 0;
}