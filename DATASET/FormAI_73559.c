//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time
    int tech_level, military_strength, population_density, environmental_conditions;
    float invasion_prob;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the following information:\n");
    printf("Current technology level (0-100): ");
    scanf("%d", &tech_level);
    printf("Military strength (0-100): ");
    scanf("%d", &military_strength);
    printf("Population density (0-100): ");
    scanf("%d", &population_density);
    printf("Environmental conditions (0-100): ");
    scanf("%d", &environmental_conditions);
    // calculate invasion probability based on input factors
    invasion_prob = ((float) tech_level + military_strength + population_density + environmental_conditions) / 400;
    printf("\nCalculating invasion probability...\n");
    int i;
    for (i = 0; i < 5; i++) { // simulate progress bar
        printf(".");
        fflush(stdout); // force output to be printed to screen
        sleep(1); // wait for 1 second
    }
    printf("\n\nInvasion probability: %.2f%%\n", invasion_prob * 100);
    // generate random outcome based on invasion probability
    int outcome = rand() % 100;
    if (outcome < invasion_prob * 100) {
        printf("\nAlien invasion imminent! Take cover!\n");
    } else {
        printf("\nAll clear! No sign of alien invasion at this time.\n");
    }
    return 0; // exit program
}