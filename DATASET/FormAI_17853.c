//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int population, military_strength, alien_tech, invasion_prob;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the current human population: ");
    scanf("%d", &population);

    printf("Please enter the current military strength: ");
    scanf("%d", &military_strength);

    printf("Please enter the level of alien technology (1-10): ");
    scanf("%d", &alien_tech);

    printf("Calculating invasion probability...\n\n");
    invasion_prob = ((rand() % 11) + military_strength) - ((population / 100) * alien_tech);

    printf("Based on current factors, the invasion probability is: %d%%\n", invasion_prob);

    if (invasion_prob < 50) {
        printf("The probability of an alien invasion is low. Keep up the good work, soldier!\n");
    } else if (invasion_prob >= 50 && invasion_prob < 80) {
        printf("There is a moderate probability of an alien invasion. Stay vigilant!\n");
    } else {
        printf("The probability of an alien invasion is high. Prepare for the worst!\n");
    }

    return 0;
}