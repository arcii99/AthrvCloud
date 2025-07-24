//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up the random seed
    srand(time(NULL));

    // Obtaining the user inputs
    int earthPopulation, earthYears, probHabitablePlanets;
    printf("Enter the number of people on Earth: ");
    scanf("%d", &earthPopulation);
    printf("Enter the number of years until the predicted invasion: ");
    scanf("%d", &earthYears);
    printf("Enter the probability of finding habitable planets: ");
    scanf("%d", &probHabitablePlanets);

    // Alien invasion probability calculation
    int alienInvasionProb;
    alienInvasionProb = ((rand() * probHabitablePlanets) / earthYears) - (earthPopulation / 10);

    // Printing the result to the console
    printf("The probability of an alien invasion within %d years is: %d%%\n", earthYears, alienInvasionProb);

    return 0;
}