//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasion_prob = 0, alien_tech = 0, human_defense = 0;
    srand(time(0)); // seed random number generator
    int rand_num = rand() % 101; // generate a random number between 0 to 100

    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // get user's input for the level of alien technology
    printf("Please input the alien technology level (1 to 10): ");
    scanf("%d", &alien_tech);

    // get user's input for the human defense level
    printf("\nPlease input the human defense level (1 to 10): ");
    scanf("%d", &human_defense);

    // calculate the probability of alien invasion
    invasion_prob = (rand_num + alien_tech) - human_defense;

    // determine the outcome based on the probability of invasion
    printf("\n\nCalculating probability...\n\n");
    if (invasion_prob <= 25) {
        printf("Congratulations! There is a low chance of alien invasion!\n");
    } else if (invasion_prob > 25 && invasion_prob <= 50) {
        printf("There is a moderate chance of alien invasion. Be prepared!\n");
    } else if (invasion_prob > 50 && invasion_prob <= 75) {
        printf("Be cautious, there is a high chance of alien invasion!\n");
    } else {
        printf("ATTENTION! There is an EXTREMELY high chance of alien invasion. Prepare for the worst!\n");
    }

    return 0;
}