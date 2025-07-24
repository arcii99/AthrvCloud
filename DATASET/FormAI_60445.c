//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the probability of an alien invasion
float alien_invasion_probability(int a, int b, int c, int d) {
    // calculate the total number of possible invasion scenarios
    int total_scenarios = a * b * c * d;
    
    // calculate the number of scenarios where an invasion occurs
    int invasion_scenarios = a * c;
    
    // calculate the probability of an invasion
    float probability = ((float)invasion_scenarios / (float)total_scenarios) * 100.0;
    
    return probability;
}

int main() {
    // set the seed for generating random numbers
    srand(time(NULL));
    
    // generate random numbers for the input variables
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;
    int d = rand() % 10 + 1;
    
    // calculate the probability of an alien invasion
    float probability = alien_invasion_probability(a, b, c, d);
    
    // print the input variables and the probability of an invasion
    printf("Alien Invasion Probability Calculator\n");
    printf("Number of planets in our galaxy with intelligent life: %d\n", a);
    printf("Number of those planets that could support human life: %d\n", b);
    printf("Number of alien civilizations that are capable of intergalactic travel: %d\n", c);
    printf("Average number of years between each alien invasion: %d\n", d);
    printf("Probability of an alien invasion: %.2f%%\n", probability);
    
    return 0;
}