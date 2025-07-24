//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to calculate the probability of an alien invasion
int alienInvasionProbability(int numPlayers) {
    int prob;
    srand(time(0));
    prob = rand() % 101; // Generate a random number from 0 to 100
    if(numPlayers < 10) {
        prob += 10; // Increase probability by 10 if number of players is less than 10
    }
    return prob;
}

// Main function to start the program
int main() {
    int numPlayers;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of players (minimum 2, maximum 20):\n");
    scanf("%d", &numPlayers);

    if(numPlayers < 2 || numPlayers > 20) {
        printf("Invalid number of players. The program will now exit.\n");
        return 0;
    }

    int prob = alienInvasionProbability(numPlayers); // Calculate probability of invasion

    printf("Calculating probability of an alien invasion with %d players...\n", numPlayers);
    printf("---------------------------------------------------------\n");
    printf("There is a %d%% chance of an alien invasion!\n", prob);
    printf("---------------------------------------------------------\n");
    printf("Please stay alert and be prepared for an invasion!\n");

    return 0;
}