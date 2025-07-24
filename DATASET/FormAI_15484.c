//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int invasion_probability = 0;
    int aliens_attacking = 0;
    
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to Alien Invasion Probability Calculator\n");
    printf("Please input total number of aliens you believe there are in existence : ");
    scanf("%d", &aliens_attacking);
    
    if (aliens_attacking <= 0) {
        printf("Invalid input. Program will exit now!\n");
        return 1;
    }
    
    // Calculate probability of an invasion occurring
    invasion_probability = (rand() % 101) * aliens_attacking;
    
    printf("Based on our advanced algorithms, the probability of an alien invasion is %d percent\n", invasion_probability);
    
    if (invasion_probability >= 50) {
        printf("We suggest contacting your nearest intergalactic defense agency immediately!\n");
    } else {
        printf("You are safe for now! But keep a lookout in case of any suspicious extraterrestrial activities.\n");
    }
    
    printf("Thank you for using Alien Invasion Probability Calculator\n");
    return 0;
}