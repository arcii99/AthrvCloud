//FormAI DATASET v1.0 Category: Poker Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

typedef struct {
    int rank;
    int suit;
} Card;

void shuffle(Card *deck);
void deal(const Card *deck, Card *hand);
void print_hand(const Card *hand);
int evaluate_hand(const Card *hand);

int main(void) {
    Card deck[NUM_CARDS] = {0};
    Card hand[HAND_SIZE] = {0};
    int score;

    srand((unsigned) time(NULL));
    
    // initialize deck
    int i, j, count = 0;
    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[count].rank = i;
            deck[count].suit = j;
            count++;
        }
    }
    
    shuffle(deck);
    deal(deck, hand);
    print_hand(hand);
    score = evaluate_hand(hand);
    printf("Hand score: %d\n", score);
    
    return 0;
}

void shuffle(Card *deck) {
    int i, j, temp;
    Card temp_card;
    
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        // swap values at indices i and j
        temp_card = deck[i];
        deck[i] = deck[j];
        deck[j] = temp_card;
    }
}

void deal(const Card *deck, Card *hand) {
    int i;
    
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

// display hand in a readable format
void print_hand(const Card *hand) {
    char *ranks[NUM_RANKS] = {
        "Two", "Three", "Four",
        "Five", "Six", "Seven",
        "Eight", "Nine", "Ten",
        "Jack", "Queen", "King", "Ace"
    };
    char *suits[NUM_SUITS] = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };
    int i;
    
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%s of %s\n", ranks[hand[i].rank], suits[hand[i].suit]);
    }
}

// evaluate the given hand and return a score
int evaluate_hand(const Card *hand) {
    // TODO: implement card evaluation algorithm
    return 0;
}