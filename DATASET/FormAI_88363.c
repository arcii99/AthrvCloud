//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the deck
#define DECK_SIZE 52
// Define how many players are in the game
#define NUM_PLAYERS 4

// Structure to represent a card
typedef struct {
    char* suit;
    char* face;
    int value;
} Card;

// Array of the four suits
char* suits[4] = {"hearts", "diamonds", "clubs", "spades"};

// Array of the thirteen card faces
char* faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Array of players' hands
Card hands[NUM_PLAYERS][2];

// Array to keep track of which cards have been dealt
int dealt[DECK_SIZE] = {0};

// Function to shuffle the deck
void shuffleDeck(Card* deck) {
    int i, j;
    Card temp;
    
    // Initialize random number generator
    srand(time(NULL));
    
    // Shuffle deck by swapping cards randomly
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards to the players
void dealCards(Card* deck) {
    int i, j;
    int cardIndex = 0;
    
    // Reset dealt array
    for (i = 0; i < DECK_SIZE; i++) {
        dealt[i] = 0;
    }
    
    // Deal two cards to each player
    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < 2; j++) {
            // Find a card that hasn't been dealt yet
            do {
                cardIndex = rand() % DECK_SIZE;
            } while (dealt[cardIndex] == 1);
            
            // Deal the card
            hands[i][j] = deck[cardIndex];
            dealt[cardIndex] = 1;
        }
    }
}

// Function to print a card
void printCard(Card card) {
    printf("%s of %s\n", card.face, card.suit);
}

// Main function to run the game
int main() {
    // Create an array to hold the deck of cards
    Card deck[DECK_SIZE];
    int i, j;
    
    // Populate the deck with cards
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[(i * 13) + j].suit = suits[i];
            deck[(i * 13) + j].face = faces[j];
            deck[(i * 13) + j].value = j + 1;
        }
    }
    
    // Shuffle the deck
    shuffleDeck(deck);
    
    // Deal the cards
    dealCards(deck);
    
    // Print out the players' hands
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        printCard(hands[i][0]);
        printCard(hands[i][1]);
    }
    
    return 0;
}