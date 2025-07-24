//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL_POPULATION 500 // Initial population of bacteria
#define GROWTH_RATE 0.2 // Growth rate of bacteria per minute
#define MAX_POPULATION 10000 // Maximum population limit

int main() {
    int time = 0; // Time elapsed in minutes
    int population = INITIAL_POPULATION; // Current population of bacteria
    
    while (population <= MAX_POPULATION) {
        printf("At time %d, the population is %d\n", time, population);
        time++; // Increment time elapsed
        population = population + round(GROWTH_RATE * population); // Calculate new population after growth
    }
    
    printf("The population has exceeded its limit of %d\n", MAX_POPULATION);
    
    return 0;
}