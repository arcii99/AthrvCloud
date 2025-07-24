//FormAI DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

int deck[DECK_SIZE]; // Declare an integer array of size 52 to store the deck.
int playerHand[HAND_SIZE]; // Declare an integer array of size 5 to store the player's hand.
int dealerHand[HAND_SIZE]; // Declare an integer array of size 5 to store the dealer's hand.

// Function to initialize the deck.
void initializeDeck() {
    int i;
    for(i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
}

// Function to shuffle the deck.
void shuffleDeck() {
    int i, j, temp;
    for(i = 0; i < DECK_SIZE; i++) {
        // Generate a random index.
        j = rand() % DECK_SIZE;
        // Swap the ith and jth elements of the deck.
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal the cards to the players.
void dealCards() {
    int i;
    // Deal the cards to the player.
    for(i = 0; i < HAND_SIZE; i++) {
        playerHand[i] = deck[i];
    }
    // Deal the cards to the dealer.
    for(i = 0; i < HAND_SIZE; i++) {
        dealerHand[i] = deck[i + HAND_SIZE];
    }
}

// Function to print the cards in a hand.
void printHand(int hand[]) {
    int i;
    for(i = 0; i < HAND_SIZE; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

// Function to check if a hand contains a pair.
int containsPair(int hand[]) {
    int i, j;
    for(i = 0; i < HAND_SIZE; i++) {
        for(j = i + 1; j < HAND_SIZE; j++) {
            if(hand[i] % 13 == hand[j] % 13) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(0)); // Seed the random number generator.
    initializeDeck(); // Initialize the deck.
    shuffleDeck(); // Shuffle the deck.
    dealCards(); // Deal the cards to the players.
    printf("Your hand: ");
    printHand(playerHand); // Print the player's hand.
    printf("Dealer's hand: ");
    printHand(dealerHand); // Print the dealer's hand.
    if(containsPair(playerHand)) {
        printf("Congratulations! You have a pair!\n");
    }
    else {
        printf("Sorry, you don't have a pair.\n");
    }
    return 0;
}