//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

int main(void) {
    // Initialize deck of cards
    int deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Initialize players
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    int* player_hands[num_players];
    int player_scores[num_players];
    for (int i = 0; i < num_players; i++) {
        player_hands[i] = malloc(sizeof(int) * 5);
        player_scores[i] = 0;
    }
 
    // Deal cards to players
    int current_card = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < num_players; j++) {
            player_hands[j][i] = deck[current_card];
            current_card++;
        }
    }

    // Evaluate hands and determine winners
    int winner_indices[num_players];
    int max_score = 0;
    int num_winners = 0;
    for (int i = 0; i < num_players; i++) {
        // Evaluate hand
        int card_counts[13] = {0};
        int suit_counts[4] = {0};
        int score = 0;

        for (int j = 0; j < 5; j++) {
            int card = player_hands[i][j];
            int value = card % 13;
            int suit = card / 13;
            if (value == 0) {
                value = 13;
            }

            card_counts[value - 1]++;
            suit_counts[suit]++;

            if (card_counts[value - 1] > 1) {
                score += card_counts[value - 1];
            }
        }

        int straight_count = 0;
        int flush_count = 0;

        for (int j = 0; j < 4; j++) {
            if (suit_counts[j] == 5) {
                flush_count = 5;
            }
        }

        for (int j = 0; j < 13; j++) {
            if (card_counts[j] > 0) {
                straight_count++;
            } else {
                straight_count = 0;
            }

            if (straight_count == 5) {
                score = 8;
            }
        }

        if (flush_count == 5) {
            if (score > 0) {
                score = 9;
            } else {
                score = 6;
            }
        }

        if (score == 0) {
            for (int j = 12; j >= 0; j--) {
                if (card_counts[j] > 0) {
                    score = j + 1;
                    break;
                }
            }
        }

        player_scores[i] = score;

        if (score > max_score) {
            max_score = score;
            num_winners = 1;
            winner_indices[0] = i;
        } else if (score == max_score) {
            num_winners++;
            winner_indices[num_winners - 1] = i;
        }
    }

    // Print results
    printf("Player scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: Score %d\n", i + 1, player_scores[i]);
    }

    printf("Winners:\n");
    for (int i = 0; i < num_winners; i++) {
        printf("Player %d\n", winner_indices[i] + 1);
    }

    // Free memory
    for (int i = 0; i < num_players; i++) {
        free(player_hands[i]);
    }

    return 0;
}