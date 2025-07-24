//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scientific
#include <stdio.h>

int main()
{
    float alien_probability = 0.0;
    int alien_count = 0, total_planets = 0;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the total number of planets in the galaxy: ");
    scanf("%d", &total_planets);

    // Calculate the probability of at least one planet being invaded by aliens
    alien_probability = 1 - pow(0.9999, total_planets);

    // Calculate the expected number of planets to be invaded by aliens
    alien_count = (int)(alien_probability * total_planets);

    printf("\nBased on scientific calculations:\n\n");
    printf("The probability of at least one planet being invaded by aliens is: %0.2f %%\n", alien_probability * 100);
    printf("The expected number of planets to be invaded by aliens is: %d\n", alien_count);

    return 0;
}