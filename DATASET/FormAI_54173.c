//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

int main() {
    int players[MAX_PLAYERS];
    int checksum[MAX_PLAYERS];
    int roundChecksum[MAX_ROUNDS];
    int count[MAX_ROUNDS];
    int currentRound = 0;
    int currentPlayer = 0;
    int i, j;

    // Seed random number generator
    srand(time(NULL));

    // Initialize player scores and checksums
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i] = 0;
        checksum[i] = 0;
    }

    // Initialize round checksums and counts
    for (i = 0; i < MAX_ROUNDS; i++) {
        roundChecksum[i] = 0;
        count[i] = 0;
    }

    // Loop through rounds
    while (currentRound < MAX_ROUNDS) {
        printf("Round #%d\n", currentRound + 1);

        // Loop through players
        for (currentPlayer = 0; currentPlayer < MAX_PLAYERS; currentPlayer++) {
            int score = rand() % 10 + 1;
            players[currentPlayer] += score;
            checksum[currentPlayer] ^= score;
            roundChecksum[currentRound] ^= score;
            count[currentRound]++;
            printf("Player %d scored %d\n", currentPlayer + 1, score);
        }

        printf("Round summary:\n");
        printf("Checksum: %d %d %d %d\n", checksum[0], checksum[1], checksum[2], checksum[3]);
        printf("Round %d checksum: %d\n", currentRound + 1, roundChecksum[currentRound]);
        printf("Round %d count: %d\n", currentRound + 1, count[currentRound]);

        currentRound++;
    }

    printf("Game summary:\n");
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d score: %d\n", i + 1, players[i]);
        printf("Player %d checksum: %d\n", i + 1, checksum[i]);
    }

    return 0;
}