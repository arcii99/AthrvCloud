//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int invasion_probability;
    int aliens_detected;
    int planetary_defense_strength;
    int num_of_detectable_aliens;

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");

    printf("Enter the current planetary defense strength: ");
    scanf("%d", &planetary_defense_strength);

    printf("Enter the number of detectable aliens in the solar system: ");
    scanf("%d", &num_of_detectable_aliens);

    aliens_detected = rand() % num_of_detectable_aliens; // Generate a random number of detected aliens

    printf("\n***ALIEN INVASION PROBABILITY REPORT***\n\n");

    printf("Detectable aliens in the solar system: %d\n", num_of_detectable_aliens);
    printf("Aliens detected: %d\n", aliens_detected);

    if (aliens_detected >= 10) { // If 10 or more aliens are detected, the probability of invasion increases
        invasion_probability = (rand() % 21) + 80; // Generate a random number between 80 and 100
    } else {
        invasion_probability = rand() % 50; // Generate a random number between 0 and 50
    }

    printf("Probability of Alien Invasion: %d%%\n", invasion_probability);

    if (invasion_probability > planetary_defense_strength) {
        printf("ALERT! Alien invasion is highly likely. Take all necessary precautions!\n");
    } else {
        printf("Alien invasion is currently not a major threat. Stay alert and monitor the situation.\n");
    }

    return 0;
}