//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));
    float probability = (float)(rand() % 100 + 1) / 100;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please input the following data:\n");
    
    int military_strength, civilian_population, distance_to_alien_planet;
    printf("Military strength of your country: ");
    scanf("%d", &military_strength);
    printf("Civilian population of your country: ");
    scanf("%d", &civilian_population);
    printf("Distance to the alien planet (in light years): ");
    scanf("%d", &distance_to_alien_planet);

    float invasion_factor = 1.0 + (distance_to_alien_planet / 100.);
    float military_factor = (float)military_strength / 1000.;
    float population_factor = (float)civilian_population / 500000.;
    
    probability *= invasion_factor;
    probability *= military_factor;
    probability *= population_factor;

    printf("Based on the data you input, the probability of an alien invasion is: %.2f%%\n", probability * 100);

    printf("Thank you for using the Alien Invasion Probability Calculator!");

    return 0;
}