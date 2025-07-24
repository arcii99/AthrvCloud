//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_PLAYERS 4
#define NUM_ROUNDS 10
#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 1
#define MAX_DIFFERENCE 10

int main() {
    int signal_strengths[NUM_PLAYERS];
    bool active_players[NUM_PLAYERS] = {true, true, true, true};

    // Initialize random seed
    srand(time(NULL));

    // Generate initial signal strengths
    for (int i = 0; i < NUM_PLAYERS; i++) {
        signal_strengths[i] = rand() % MAX_SIGNAL_STRENGTH;
    }

    // Start game loop
    for (int round_num = 1; round_num <= NUM_ROUNDS; round_num++) {
        printf("Round %d\n", round_num);

        // Print active players and signal strengths
        printf("Active Players:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (active_players[i]) {
                printf("Player %d - Signal Strength: %d\n", i+1, signal_strengths[i]);
            }
        }

        // Players choose opponents to challenge
        int challenge_pairs[NUM_PLAYERS][2];
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (active_players[i]) {
                printf("Player %d, choose an opponent to challenge: ", i+1);
                scanf("%d", &challenge_pairs[i][0]);
                challenge_pairs[i][0]--;

                while (!active_players[challenge_pairs[i][0]] || challenge_pairs[i][0] == i) {
                    printf("Invalid selection. Please choose a different opponent: ");
                    scanf("%d", &challenge_pairs[i][0]);
                    challenge_pairs[i][0]--;
                }

                printf("Player %d, choose another opponent to challenge: ", i+1);
                scanf("%d", &challenge_pairs[i][1]);
                challenge_pairs[i][1]--;

                while (!active_players[challenge_pairs[i][1]] || challenge_pairs[i][0] == challenge_pairs[i][1] || challenge_pairs[i][1] == i) {
                    printf("Invalid selection. Please choose a different opponent: ");
                    scanf("%d", &challenge_pairs[i][1]);
                    challenge_pairs[i][1]--;
                }
            }
        }

        // Calculate new signal strengths
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (active_players[i]) {
                int opponent1 = challenge_pairs[i][0];
                int opponent2 = challenge_pairs[i][1];

                int avg_strength = (signal_strengths[opponent1] + signal_strengths[opponent2] + signal_strengths[i]) / 3;
                int difference1 = abs(signal_strengths[i] - signal_strengths[opponent1]);
                int difference2 = abs(signal_strengths[i] - signal_strengths[opponent2]);

                if (difference1 > MAX_DIFFERENCE || difference2 > MAX_DIFFERENCE) {
                    signal_strengths[i] -= (avg_strength - signal_strengths[i]) * 0.4;
                } else {
                    signal_strengths[i] = avg_strength;
                }

                // Check if player has been eliminated
                if (signal_strengths[i] < MIN_SIGNAL_STRENGTH) {
                    active_players[i] = false;
                    printf("Player %d has been eliminated!\n", i+1);
                }
            }
        }

        // Check if game is over
        int active_count = 0;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (active_players[i]) {
                active_count++;
            }
        }
        if (active_count == 1) {
            printf("Game over! Player %d is the winner!\n", getWinner(active_players));
            return 0;
        }
    }

    printf("Game over! Player %d is the winner!\n", getWinner(active_players));

    return 0;
}

int getWinner(bool active_players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (active_players[i]) {
            return i+1;
        }
    }
}