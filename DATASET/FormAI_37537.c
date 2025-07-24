//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_aliens, num_attempts;
    double invasion_prob;
    // Seed the random number generator with the current time
    srand(time(NULL));
    // Prompt the user for input
    printf("How many aliens are estimated to exist?\n");
    scanf("%d", &num_aliens);
    printf("How many attempts will be made to make contact with the aliens?\n");
    scanf("%d", &num_attempts);
    // Calculate the invasion probability using a randomly generated number
    invasion_prob = (double) rand() / RAND_MAX;
    // Calculate the estimated number of aliens that will invade
    int num_invaders = invasion_prob * num_aliens;
    // Calculate the average number of attempts needed to make contact
    double avg_attempts = (double) num_aliens / num_attempts;
    // Display the results to the user
    printf("There is a %.2f%% chance of an alien invasion\n", invasion_prob*100);
    printf("At this rate, an estimated %d aliens will invade\n", num_invaders);
    printf("On average, it will take %.2f attempts to make contact with a single alien\n", avg_attempts);
    return 0;
}