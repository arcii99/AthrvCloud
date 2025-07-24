//FormAI DATASET v1.0 Category: Poker Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to return a random number between 0-51
int random_card() {
    return rand() % 52;
}

// Function to shuffle the deck of cards
void shuffle_deck(int *deck) {
    for (int i = 0; i < 52; i++) {
        int r = random_card();
        int temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// Function to print the card
void print_card(int card) {
    char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    printf("%s of %s\n", ranks[card % 13], suits[card / 13]);
}

// Function to print the hand
void print_hand(int *hand) {
    printf("Your hand:\n");
    for (int i = 0; i < 5; i++) {
        print_card(hand[i]);
    }
}

// Function to check if a hand is a flush
int is_flush(int *hand) {
    int suit = hand[0] / 13;
    for (int i = 1; i < 5; i++) {
        if (hand[i] / 13 != suit) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));  // Seed for random number generator
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    shuffle_deck(deck);

    int hand[5];
    for (int i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    print_hand(hand);

    if (is_flush(hand)) {
        printf("You have a flush!\n");
    } else {
        printf("You do not have a flush.\n");
    }

    return 0;
}