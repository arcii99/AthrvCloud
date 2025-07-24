//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int alienDistance, defenseTurrets, missileLaunchers, alienInvasionProb;

    // Seed the random number generator with current time
    srand(time(0));

    // Get input values from user
    printf("Enter the distance between Earth and Alien planet (in light years): ");
    scanf("%d", &alienDistance);

    printf("Enter the number of Defense Turrets available: ");
    scanf("%d", &defenseTurrets);

    printf("Enter the number of Missile Launchers available: ");
    scanf("%d", &missileLaunchers);

    // Calculate the probability of alien invasion
    alienInvasionProb = (defenseTurrets + missileLaunchers) * 10 / alienDistance;

    // Print the probability of alien invasion
    printf("\nProbability of Alien Invasion: %d%%\n", alienInvasionProb);

    // Generate a random number between 1 and 100
    int randomNumber = generateRandomNumber(1, 100);

    // Check if the alien invasion occurs based on the random number generated
    if (randomNumber <= alienInvasionProb)
    {
        printf("\nAlien Invasion has occurred!\n");
    }
    else
    {
        printf("\nNo Alien Invasion has occurred.\n");
    }

    return 0;
}