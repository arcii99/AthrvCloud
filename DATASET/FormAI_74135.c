//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateProbability(int level, int distance, int attack, int defense) {
    /* Insert probability calculation logic here */
}

int main() {
    int level, distance, attack, defense, probability;
    
    /* User input prompt section */
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the following details to calculate the probability of an Alien Invasion:\n");
    printf("Enter the level of the Alien civilization (1-10): ");
    scanf("%d", &level);
    printf("Enter the distance from Earth to the Alien civilization (in light years): ");
    scanf("%d", &distance);
    printf("Enter the attack power of Alien Spaceships (1-100): ");
    scanf("%d", &attack);
    printf("Enter the defense power of Earth Spaceships (1-100): ");
    scanf("%d", &defense);
    
    /* Probability calculation section */
    srand(time(0)); /* Random seed generation */
    probability = calculateProbability(level, distance, attack, defense);
    
    /* Result display section */
    printf("The probability of an Alien Invasion is: %d%%\n", probability);
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    
    return 0;
}