//FormAI DATASET v1.0 Category: Poker Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    int face;
    int suit;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
} Hand;

void print_card(Card c) {
    char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char faces[13][6] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("%s of %s", faces[c.face], suits[c.suit]);
}

void print_hand(Hand h) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(h.cards[i]);
        printf("\n");
    }
}

void shuffle_deck(Card* deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Hand* h, Card* deck) {
    for (int i = 0; i < HAND_SIZE; i++) {
        h->cards[i] = deck[i];
    }
}

int evaluate_hand(Hand h) {
    int num_pairs = 0;
    int three_of_a_kind = 0;
    int four_of_a_kind = 0;
    int flush = 1;
    int straight = 1;

    int face_counts[13] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        face_counts[h.cards[i].face]++;
        if (i < HAND_SIZE - 1 && h.cards[i].suit != h.cards[i+1].suit) {
            flush = 0;
        }
        if (i < HAND_SIZE - 1 && h.cards[i].face != h.cards[i+1].face - 1) {
            straight = 0;
        }
    }

    for (int i = 0; i < 13; i++) {
        if (face_counts[i] == 2) {
            num_pairs++;
        }
        if (face_counts[i] == 3) {
            three_of_a_kind = 1;
        }
        if (face_counts[i] == 4) {
            four_of_a_kind = 1;
        }
    }

    if (flush && straight) {
        return 50;
    }
    if (four_of_a_kind) {
        return 25;
    }
    if (three_of_a_kind && num_pairs == 1) {
        return 10;
    }
    if (flush) {
        return 7;
    }
    if (straight) {
        return 5;
    }
    if (three_of_a_kind) {
        return 3;
    }
    if (num_pairs == 2) {
        return 2;
    }
    return 0;
}

int main() {
    Card deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].face = i % 13;
        deck[i].suit = i / 13;
    }

    shuffle_deck(deck);

    Hand player_hand;

    deal(&player_hand, deck);

    printf("Your hand:\n");
    print_hand(player_hand);

    int score = evaluate_hand(player_hand);
    printf("Your score: %d\n", score);

    return 0;
}