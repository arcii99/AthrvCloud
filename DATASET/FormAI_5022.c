//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level_of_technology, military_strength, population, probability;
    srand(time(NULL));
    printf("------------- Alien Invasion Probability Calculator ------------\n");
    printf("Enter the level of technology of your civilization (1-10): ");
    scanf("%d", &level_of_technology);
    printf("Enter the military strength of your civilization (1-10): ");
    scanf("%d", &military_strength);
    printf("Enter the population of your civilization: ");
    scanf("%d", &population);
    probability = rand() % 101;
    if (probability < 10) {
        printf("Congratulations! Your civilization is invulnerable to alien invasion.\n");
        printf("Probability of alien invasion: 0%%\n");
    } else {
        probability = (level_of_technology + military_strength + population) * (probability / 10);
        printf("Probability of alien invasion: %d%%\n", probability);
        if (probability > 50) {
            printf("Warning! Your civilization is at a high risk of alien invasion!\n");
            printf("Prepare your military and defenses!\n");
        } else {
            printf("Your civilization is at a moderate risk of alien invasion.\n");
            printf("It is advised to increase your military and defenses.\n");
        }
    }
    return 0;
}