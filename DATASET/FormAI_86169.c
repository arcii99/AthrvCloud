//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Variables for user input
    int population;
    int military;
    int technology;

    // Generate random number for alien invasion probability
    srand(time(NULL));
    int probability = rand() % 101;

    // Get input from user
    printf("Please enter the population of Earth: ");
    scanf("%d", &population);

    printf("Please enter the size of the military on Earth: ");
    scanf("%d", &military);

    printf("Please enter the level of technology on Earth (1-10): ");
    scanf("%d", &technology);

    // Calculate score based on user input
    int score = (population * 0.2) + (military * 0.3) + (technology * 0.5);

    // Display user input and final probability
    printf("=======================================\n");
    printf("Population: %d\n", population);
    printf("Military: %d\n", military);
    printf("Technology: %d\n", technology);
    printf("=======================================\n");
    printf("Probability of Alien Invasion: %d%%\n", probability);
    printf("=======================================\n");
    printf("Your Earth Defense Score: %d\n", score);
    printf("=======================================\n");

    // Determine if Earth is at high risk for invasion
    if (probability > 50 && score < 100) {
        printf("WARNING: High Risk of Alien Invasion!\n");
    } else {
        printf("Earth is Safe...For Now.\n");
    }

    return 0;
}