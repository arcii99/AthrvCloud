//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    int num_battles;
    double alien_prob, invasion_prob;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of battles: ");
    scanf("%d", &num_battles);

    for(int i = 1; i <= num_battles; i++) {
        printf("\nBattle %d:\n", i);
        alien_prob = (double) rand() / RAND_MAX; // Generate random alien probability
        printf("Alien probability: %.2f\n", alien_prob);
        
        if(alien_prob <= 0.5) {
            invasion_prob = alien_prob + 0.1; // Calculate invasion probability
            printf("Invasion probability: %.2f\n", invasion_prob);
        } else {
            invasion_prob = alien_prob + 0.4;
            printf("Invasion probability: %.2f\n", invasion_prob);
        }
        
        if(invasion_prob <= 0.25) {
            printf("Alien invasion will not occur.\n");
        } else if(invasion_prob <= 0.75) {
            printf("Alien invasion may occur.\n");
        } else {
            printf("Alien invasion is highly likely.\n");
        }
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}