//FormAI DATASET v1.0 Category: Poker Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define HAND_SIZE 5
#define NUM_PLAYERS 2

// Card structure
struct Card {
    int value;
    char suit;
};

// Function to generate a new deck of cards
void generate_deck(struct Card* deck) {
    int i, j;
    int value = 1;

    for(i=0; i<NUM_CARDS; i++) {
        if(value > 13) {
            value = 1;
        }

        if(i%13 == 0) {
            deck[i].value = value;
            value++;
        } else {
            deck[i].value = value;
        }

        if(i < 13) {
            deck[i].suit = 'S';  // Spade
        } else if(i < 26) {
            deck[i].suit = 'C';  // Club
        } else if(i < 39) {
            deck[i].suit = 'D';  // Diamond
        } else {
            deck[i].suit = 'H';  // Heart
        }
    }
}

// Function to shuffle the deck
void shuffle_deck(struct Card* deck) {
    int i, j;
    struct Card temp_card;

    for(i=0; i<NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;

        temp_card = deck[i];
        deck[i] = deck[j];
        deck[j] = temp_card;
    }
}

// Function to deal cards to all players
void deal_cards(struct Card* deck, struct Card hand[][HAND_SIZE]) {
    int i, j, k = 0;

    for(i=0; i<NUM_PLAYERS; i++) {
        for(j=0; j<HAND_SIZE; j++) {
            hand[i][j] = deck[k];
            k++;
        }
    }
}

// Function to print cards
void print_card(struct Card card) {
    if(card.value == 1) {
        printf("Ace");
    } else if(card.value == 11) {
        printf("Jack");
    } else if(card.value == 12) {
        printf("Queen");
    } else if(card.value == 13) {
        printf("King");
    } else {
        printf("%d", card.value);
    }

    printf(" of %c\n", card.suit);
}

// Function to print a hand
void print_hand(struct Card hand[]) {
    int i;

    for(i=0; i<HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}

// Function to determine the winner
int determine_winner(struct Card hand[][HAND_SIZE]) {
    int i, j, k;
    int winner = 0;
    int highest_score = 0;
    int score_sum[NUM_PLAYERS] = {0};

    // Calculate score for each hand
    for(i=0; i<NUM_PLAYERS; i++) {
        int pairs[HAND_SIZE] = {0};
        score_sum[i] = 0;

        // Check for pairs
        for(j=0; j<HAND_SIZE; j++) {
            for(k=j+1; k<HAND_SIZE; k++) {
                if(hand[i][j].value == hand[i][k].value) {
                    pairs[j] = 1;
                    pairs[k] = 1;
                }
            }
        }

        // Calculate score based on pairs
        for(j=0; j<HAND_SIZE; j++) {
            if(pairs[j] == 1) {
                if(hand[i][j].value == 1) {
                    score_sum[i] += 14;
                } else {
                    score_sum[i] += hand[i][j].value;
                }
            } else {
                score_sum[i] += 0;
            }
        }

        // Check for flush
        int flush = 1;
        for(j=0; j<(HAND_SIZE-1); j++) {
            if(hand[i][j].suit != hand[i][j+1].suit) {
                flush = 0;
                break;
            }
        }

        if(flush == 1) {
            score_sum[i] += 100;
        }

        if(score_sum[i] > highest_score) {
            highest_score = score_sum[i];
            winner = i;
        }
    }

    return winner;
}

int main() {
    struct Card deck[NUM_CARDS];
    struct Card player_hands[NUM_PLAYERS][HAND_SIZE];
    int winner;
    srand(time(0));  // Seed random number generator

    generate_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, player_hands);

    printf("Player 1's hand:\n");
    print_hand(player_hands[0]);

    printf("Player 2's hand:\n");
    print_hand(player_hands[1]);

    winner = determine_winner(player_hands);

    printf("Player %d wins!\n", winner+1);

    return 0;
}