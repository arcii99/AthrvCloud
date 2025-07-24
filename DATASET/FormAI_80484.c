//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int aliens_detected, alien_prob, invasion_prob;
    srand(time(NULL));   // Seed the random number generator with current time

    printf("Enter the number of aliens detected: ");
    scanf("%d", &aliens_detected);

    // Calculate the probability of an alien invasion based on the number of aliens detected
    if (aliens_detected <= 10)
        alien_prob = 1;   // Low probability of alien invasion
    else if (aliens_detected > 10 && aliens_detected <= 20)
        alien_prob = 2;
    else if (aliens_detected > 20 && aliens_detected <= 30)
        alien_prob = 3;
    else if (aliens_detected > 30 && aliens_detected <= 40)
        alien_prob = 4;
    else
        alien_prob = 5;   // High probability of alien invasion

    // Generate a random number between 1 and 10 to add some randomness to the invasion probability
    int rand_num = rand() % 10 + 1;
    invasion_prob = alien_prob + rand_num;

    // Display the results to the user
    printf("Based on the number of aliens detected, the probability of an alien invasion is %d%%.\n", invasion_prob);
    printf("Note: This is just a probability calculation and does not reflect the actual probability of an alien invasion.\n");

    return 0;
}