//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to calculate probability of Alien Invasion
int calculateProbability(int no_of_players) {
    int probability = rand() % (200 - 100 + 1) + 100; // Generating probability between 100 to 200
    probability *= no_of_players; // Increasing probability based on number of players
    return probability;
}

int main() {
    srand((unsigned) time(NULL)); // Setting seed for random number generation
    int no_of_players = 0;
    printf("Welcome to Alien Invasion Probability Calculator!\n");
    printf("Enter number of players: ");
    scanf("%d", &no_of_players);
    if(no_of_players < 1) { // Checking if valid number of players entered
        printf("Invalid number of players!\n");
        return 0;
    }
    
    int probability = calculateProbability(no_of_players);
    printf("Probability of Alien Invasion: %d%%\n", probability);
    printf("May the odds be ever in your favor!\n");
    
    return 0;
}