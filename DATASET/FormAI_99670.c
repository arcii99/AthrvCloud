//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_HANDS 2
#define NUM_CARDS_PER_HAND 5

// Global variables
char ranks[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char suits[NUM_SUITS] = {'C', 'D', 'H', 'S'};
int deck[DECK_SIZE] = {0};
int hands[NUM_HANDS][NUM_CARDS_PER_HAND] = {{0}};
int player_score[NUM_HANDS] = {0};

// Shuffle deck
void shuffle_deck() {
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Initialize deck
void init_deck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
}

// Print card
void print_card(int card) {
    int rank = card % NUM_RANKS;
    int suit = card / NUM_RANKS;
    printf("%c%c ", ranks[rank], suits[suit]);
}

// Print hand
void print_hand(int hand[NUM_CARDS_PER_HAND]) {
    for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
        print_card(hand[i]);
    }
    printf("\n");
}

// Deal hand
void deal_hand(int hand[NUM_CARDS_PER_HAND], int index) {
    for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
        hand[i] = deck[NUM_CARDS_PER_HAND * index + i];
    }
}

// Calculate score of hand
int calculate_score(int hand[NUM_CARDS_PER_HAND]) {
    int score = 0;
    int has_ace = 0;
    int num_aces = 0;
    for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
        int card = hand[i];
        int rank = card % NUM_RANKS;
        if (rank >= 8) {
            score += 10;
        } else if (rank == 0) {
            has_ace = 1;
            num_aces++;
            score += 11;
        } else {
            score += rank + 2;
        }
    }
    while (num_aces > 0 && score > 21) {
        score -= 10;
        num_aces--;
    }
    return score;
}

// Calculate winner
int calculate_winner() {
    int winner = 0;
    int high_score = player_score[0];
    for (int i = 1; i < NUM_HANDS; i++) {
        if (player_score[i] > high_score && player_score[i] <= 21) {
            high_score = player_score[i];
            winner = i;
        }
    }
    return winner;
}

int main() {
    // Initialize deck
    init_deck();

    // Shuffle deck
    shuffle_deck();

    // Deal hands
    for (int i = 0; i < NUM_HANDS; i++) {
        deal_hand(hands[i], i);
    }

    // Print hands
    for (int i = 0; i < NUM_HANDS; i++) {
        printf("Hand %d: ", i + 1);
        print_hand(hands[i]);
        player_score[i] = calculate_score(hands[i]);
        printf("Score: %d\n", player_score[i]);
    }

    // Calculate winner
    int winner = calculate_winner();
    if (winner >= 0) {
        printf("Hand %d wins!\n", winner + 1);
    } else {
        printf("No winner.\n");
    }

    return 0;
}