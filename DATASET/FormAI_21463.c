//FormAI DATASET v1.0 Category: Poker Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck of cards
void shuffle(int deck[]) {
    int i, j, temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print player's hand
void print_hand(int *hand) {
    int i;
    printf("Your hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

// Function to calculate the rank of player's hand
int rank_hand(int *hand) {
    int i, j, rank = 0;
    int freq[14] = {0};
    int suit[4] = {0};
    int max_freq = 0;
    int max_suit = 0;

    // Count the frequency of each rank and suit
    for (i = 0; i < 5; i++) {
        freq[hand[i] % 13]++;
        suit[hand[i] / 13]++;
    }

    // Check for flush
    for (i = 0; i < 4; i++) {
        if (suit[i] == 5) {
            rank = 6;
            break;
        }
    }

    // Check for straight
    for (i = 0; i < 10; i++) {
        if (freq[i] && freq[i+1] && freq[i+2] && freq[i+3] && freq[i+4]) {
            rank = 5;
            break;
        }
    }

    // Check for four of a kind
    for (i = 0; i < 13; i++) {
        if (freq[i] == 4) {
            rank = 8;
            break;
        }
    }

    // Check for three of a kind and a pair
    for (i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            for (j = 0; j < 13; j++) {
                if (freq[j] == 2 && j != i) {
                    rank = 7;
                    break;
                }
            }
            if (rank == 7) {
                break;
            }
        }
    }

    // Check for three of a kind
    for (i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            rank = 4;
            break;
        }
    }

    // Check for two pairs
    for (i = 0; i < 13; i++) {
        if (freq[i] == 2 && max_freq) {
            rank = 3;
            break;
        } else if (freq[i] == 2) {
            max_freq = freq[i];
        }
    }

    // Check for a pair
    for (i = 0; i < 13; i++) {
        if (freq[i] == 2) {
            rank = 2;
            break;
        }
    }

    // Check for high card
    if (rank == 0) {
        rank = 1;
    }

    return rank;
}

// Function to compare the rank of two hands
int compare_hand(int *hand1, int *hand2) {
    int rank1 = rank_hand(hand1);
    int rank2 = rank_hand(hand2);

    if (rank1 > rank2) {
        return 1;
    } else if (rank1 < rank2) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int deck[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                  13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 
                  25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 
                  37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
                  49, 50, 51};
    int player_hand[5];
    int opponent_hand[5];
    int i, j, choice;
    char *rank_str[] = {"", "High card", "One pair", "Two pairs", "Three of a kind",
                        "Straight", "Flush", "Full house", "Four of a kind", "Straight flush"};

    srand(time(NULL));
    shuffle(deck);

    // Deal cards to player and opponent
    for (i = 0; i < 5; i++) {
        player_hand[i] = deck[i];
        opponent_hand[i] = deck[i+5];
    }

    // Print player's hand
    print_hand(player_hand);

    // Ask player which cards to discard and redraw
    printf("Enter the numbers of the cards you want to discard and redraw (e.g. 1 3):\n");
    scanf("%d %d", &i, &j);
    player_hand[i-1] = deck[10];
    player_hand[j-1] = deck[11];

    // Print player's new hand and rank
    print_hand(player_hand);
    printf("Your hand is %s\n", rank_str[rank_hand(player_hand)]);

    // Opponent discards and redraws
    // If rank of opponent's hand is greater than player's, opponent wins
    for (i = 0; i < 5; i++) {
        if (opponent_hand[i] % 13 >= 10) {
            opponent_hand[i] = deck[10];
        }
    }
    printf("Opponent has redrawn.\n");
    if (compare_hand(player_hand, opponent_hand) == -1) {
        printf("Opponent wins with a %s.\n", rank_str[rank_hand(opponent_hand)]);
    } else {
        printf("You win!\n");
    }

    return 0;
}