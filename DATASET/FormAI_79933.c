//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52

typedef struct Card {
    int rank;
    int suit;
} Card;

typedef struct Deck {
    Card cards[NUM_CARDS];
    int current_card;
} Deck;

void shuffle_deck(Deck *deck);
void deal_hands(Card hands[2][2], Deck *deck);
void print_card(Card card);
void print_hand(Card hand[2]);
int evaluate_hand(Card hand[2]);
char *rank_to_string(int rank);
char *suit_to_string(int suit);

int main() {
    srand(time(NULL));
    Deck deck = {
        .cards = {
            {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0},
            {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1}, {12, 1}, {13, 1},
            {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {13, 2},
            {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}, {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {13, 3},
        },
        .current_card = 0
    };
    shuffle_deck(&deck);

    Card hands[2][2];
    deal_hands(hands, &deck);

    printf("Player 1:\n");
    print_hand(hands[0]);
    printf("Player 2:\n");
    print_hand(hands[1]);

    int p1_score = evaluate_hand(hands[0]);
    int p2_score = evaluate_hand(hands[1]);

    printf("Player 1 score: %d\n", p1_score);
    printf("Player 2 score: %d\n", p2_score);

    if (p1_score > p2_score) {
        printf("Player 1 wins!\n");
    } else if (p2_score > p1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void shuffle_deck(Deck *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int rand_index = rand() % NUM_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[rand_index];
        deck->cards[rand_index] = temp;
    }
    deck->current_card = 0;
}

void deal_hands(Card hands[2][2], Deck *deck) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hands[i][j] = deck->cards[deck->current_card++];
        }
    }
}

void print_card(Card card) {
    printf("%s of %s\n", rank_to_string(card.rank), suit_to_string(card.suit));
}

void print_hand(Card hand[2]) {
    for (int i = 0; i < 2; i++) {
        print_card(hand[i]);
    }
}

int evaluate_hand(Card hand[2]) {
    int score = 0;
    for (int i = 0; i < 2; i++) {
        score += hand[i].rank;
    }
    return score;
}

char *rank_to_string(int rank) {
    switch (rank) {
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
    }
    return NULL;
}

char *suit_to_string(int suit) {
    switch (suit) {
        case 0:
            return "Clubs";
        case 1:
            return "Diamonds";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
    }
    return NULL;
}