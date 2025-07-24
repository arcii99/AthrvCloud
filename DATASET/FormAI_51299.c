//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int years;
    printf("Enter number of years to calculate probability for: ");
    scanf("%d", &years);

    srand(time(NULL)); // Seed for random number generation

    float probability = 0.01; // Base probability of alien invasion
    int num_iterations = years * 365; // Number of iterations to simulate years
    for(int i = 0; i < num_iterations; i++) {
        float chance_of_earthquake = (float)rand() / RAND_MAX; // Random number between 0 and 1
        if(chance_of_earthquake < 0.005) { // 0.5% chance of devastating earthquake
            probability += 0.1; // Increases probability by 10%
        }
        float chance_of_supernova = (float)rand() / RAND_MAX; // Random number between 0 and 1
        if(chance_of_supernova < 0.001) { // 0.1% chance of nearby supernova
            probability += 0.3; // Increases probability by 30%
        }
        float chance_of_radio_signal = (float)rand() / RAND_MAX; // Random number between 0 and 1
        if(chance_of_radio_signal < 0.01) { // 1% chance of detecting a radio signal from space
            probability += 0.05; // Increases probability by 5%
        }
        float chance_of_random_event = (float)rand() / RAND_MAX; // Random number between 0 and 1
        if(chance_of_random_event < 0.002) { // 0.2% chance of any other random event
            probability += 0.2; // Increases probability by 20%
        }
    }

    probability *= 100; // Convert to percentage
    if(probability > 100) probability = 100; // Maximum probability is 100%
    printf("The probability of alien invasion in %d years is: %.2f%%\n", years, probability);

    return 0;
}