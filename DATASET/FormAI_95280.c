//FormAI DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of iterations
#define ITERATIONS 100000

// Number of players
#define NUM_PLAYERS 4

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int player_scores[NUM_PLAYERS] = {0};
    int i, j;

    // Seed random number generator
    srand(time(NULL));

    // Run benchmarking loop
    for (i = 0; i < ITERATIONS; i++) {
        // Simulate players taking turns
        for (j = 0; j < NUM_PLAYERS; j++) {
            // Generate a random score between 1 and 10
            int score = generateRandomNumber(1, 10);

            // Add score to player's total
            player_scores[j] += score;
        }
    }

    // Print out each player's average score
    printf("Player scores:\n");
    for (i = 0; i < NUM_PLAYERS; i++) {
        double avg_score = (double)player_scores[i] / ITERATIONS;
        printf("Player %d: %.2f\n", i+1, avg_score);
    }

    return 0;
}