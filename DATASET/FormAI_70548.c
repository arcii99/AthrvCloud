//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ALIEN_PROB_MIN 1
#define ALIEN_PROB_MAX 10
#define DEFENSE_LEVEL_MIN 1
#define DEFENSE_LEVEL_MAX 5
#define ECONOMY_FACTOR_MIN 1
#define ECONOMY_FACTOR_MAX 5

int main(){
    int alien_probability, defense_level, economy_factor;
    float invasion_probability;
    srand(time(NULL));
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the alien probability level (1-10): ");
    scanf("%d", &alien_probability);
    printf("Please enter the defense level (1-5): ");
    scanf("%d", &defense_level);
    printf("Please enter the economy factor (1-5): ");
    scanf("%d", &economy_factor);
    
    // Add configurable randomness to the calculation
    alien_probability += rand() % (ALIEN_PROB_MAX - ALIEN_PROB_MIN + 1) + ALIEN_PROB_MIN;
    defense_level += rand() % (DEFENSE_LEVEL_MAX - DEFENSE_LEVEL_MIN + 1) + DEFENSE_LEVEL_MIN;
    economy_factor += rand() % (ECONOMY_FACTOR_MAX - ECONOMY_FACTOR_MIN + 1) + ECONOMY_FACTOR_MIN;
    
    // Calculate probability of an alien invasion
    invasion_probability = (float)(alien_probability * defense_level) / (float)economy_factor;
    
    printf("\nProbability of an alien invasion: %.2f%%\n", invasion_probability);
    
    return 0;
}