//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card suits
enum suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

// Define card ranks
enum ranks {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

// Define a card structure
struct Card {
    int rank;
    int suit;
};

// Initialize the deck of cards
void initialize_deck(struct Card deck[]) {
    int i, j, card_count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[card_count].rank = j;
            deck[card_count].suit = i;
            card_count++;
        }
    }
}

// Shuffle the deck of cards
void shuffle_deck(struct Card deck[]) {
    int i, j;
    struct Card temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal cards to each player
void deal_cards(struct Card deck[], struct Card player_1[], struct Card player_2[], struct Card player_3[]) {
    int i;
    for (i = 0; i < 3; i++) {
        player_1[i] = deck[i];
        player_2[i] = deck[i+3];
        player_3[i] = deck[i+6];
    }
}

// Determine the winner of the game
int determine_winner(struct Card player_1[], struct Card player_2[], struct Card player_3[]) {
    int i, p1_value = 0, p2_value = 0, p3_value = 0;

    // Calculate the total value of each player's hand
    for (i = 0; i < 3; i++) {
        p1_value += player_1[i].rank + 1;
        p2_value += player_2[i].rank + 1;
        p3_value += player_3[i].rank + 1;
    }

    // Determine the winner
    if (p1_value > p2_value && p1_value > p3_value) {
        return 1;
    } else if (p2_value > p1_value && p2_value > p3_value) {
        return 2;
    } else if (p3_value > p1_value && p3_value > p2_value) {
        return 3;
    } else {
        // In case of a tie, determine the winner by suit
        for (i = 2; i >= 0; i--) {
            if (player_1[i].suit > player_2[i].suit && player_1[i].suit > player_3[i].suit) {
                return 1;
            } else if (player_2[i].suit > player_1[i].suit && player_2[i].suit > player_3[i].suit) {
                return 2;
            } else if (player_3[i].suit > player_1[i].suit && player_3[i].suit > player_2[i].suit) {
                return 3;
            }
        }
    }
}

int main() {
    struct Card deck[52];
    struct Card player_1[3];
    struct Card player_2[3];
    struct Card player_3[3];
    int winner;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize and shuffle the deck of cards
    initialize_deck(deck);
    shuffle_deck(deck);

    // Deal cards to each player
    deal_cards(deck, player_1, player_2, player_3);

    // Determine the winner of the game
    winner = determine_winner(player_1, player_2, player_3);

    // Print out the results of the game
    printf("Player %d wins!\n", winner);

    return 0;
}