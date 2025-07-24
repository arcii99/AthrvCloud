//FormAI DATASET v1.0 Category: Poker Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

// Struct for a card
struct Card {
    int rank, suit;
};

// Function to shuffle a deck of cards
void shuffle(struct Card *deck) {
    int i, j;
    struct Card tmp;
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = deck[j];
        deck[j] = deck[i];
        deck[i] = tmp;
    }
}

// Function to print a card
void print_card(struct Card c) {
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[] = {'C', 'D', 'H', 'S'};
    printf("%c%c ", ranks[c.rank], suits[c.suit]);
}

// Function to print a hand
void print_hand(struct Card *hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++)
        print_card(hand[i]);
}

// Function to determine if a hand contains a pair or two pairs
int has_pair(struct Card *hand) {
    int i, j, count = 0;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        for (j = i + 1; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank)
                count++;
        }
    }
    if (count == 1)
        return 1;
    else if (count == 2)
        return 2;
    else
        return 0;
}

// Function to determine if a hand contains three of a kind or a full house
int has_three_of_a_kind(struct Card *hand) {
    int i, j, count = 0;
    for (i = 0; i < HAND_SIZE - 2; i++) {
        for (j = i + 1; j < HAND_SIZE - 1; j++) {
            if (hand[i].rank == hand[j].rank) {
                count++;
                if (j == HAND_SIZE - 2 && hand[j].rank == hand[j+1].rank)
                    count++;
                else if (j == HAND_SIZE - 2)
                    return count;
            }
        }
    }
    return count;
}

// Main function to play the game
int main() {
    struct Card deck[NUM_CARDS];
    int i, j, count;
    srand((unsigned)time(NULL));
    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[i * NUM_SUITS + j].rank = i;
            deck[i * NUM_SUITS + j].suit = j;
        }
    }
    shuffle(deck);
    struct Card hand[HAND_SIZE];
    for (i = 0; i < HAND_SIZE; i++)
        hand[i] = deck[i];
    printf("Your hand: ");
    print_hand(hand);
    count = has_pair(hand);
    if (count == 1)
        printf("\nYou have a pair!\n");
    else if (count == 2)
        printf("\nYou have two pairs!\n");
    else {
        count = has_three_of_a_kind(hand);
        if (count == 1)
            printf("\nYou have three of a kind!\n");
        else if (count == 2)
            printf("\nYou have a full house!\n");
        else
            printf("\nYou have nothing.\n");
    }
    return 0;
}