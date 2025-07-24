//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alien_ships, earth_population, invasion_probability;
 
    srand(time(0));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the number of alien ships currently spotted near Earth: ");
    scanf("%d", &alien_ships);
   
    printf("\n");
   
    printf("Please enter the current Earth population: ");
    scanf("%d", &earth_population);
  
   
    invasion_probability = (rand() % 100) + 1;
    printf("\nCalculating invasion probability...\n\n");
   
    if (invasion_probability > 50) {
        printf("The probability of an alien invasion is %d%%.\n", invasion_probability);
        printf("Take cover and prepare for the worst!\n");
    } else {
        printf("The probability of an alien invasion is %d%%.\n", invasion_probability);
        printf("There's no need to panic (yet)...\n");
    }

    return 0;
}