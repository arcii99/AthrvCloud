//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("********** ALIEN INVASION PROBABILITY CALCULATOR **********\n\n");

    srand(time(0));
    
    int num_aliens = rand() % 100; // Generating the number of aliens between 0 and 100
    float alien_strength = (float) (rand() % 1000) / 1000; // Generating the alien strength between 0 and 1
    
    printf("Generating random numbers...\n\n");
    printf("Number of Aliens: %d\nAlien Strength: %.2f\n\n", num_aliens, alien_strength);
    
    float battle_strength; // To store the battle strength of humans
    
    printf("Enter the battle strength of humans (between 0 and 1): ");
    scanf("%f", &battle_strength);
    
    if (battle_strength < 0 || battle_strength > 1) {
        printf("Invalid input. Please enter a number between 0 and 1.\n");
        return 0;
    }
    
    float probability = (1 - alien_strength) * num_aliens * battle_strength; // Calculating the probability of alien invasion
    
    printf("\nALIEN INVASION PROBABILITY: %.2f%%\n", probability * 100);
    
    return 0;
}