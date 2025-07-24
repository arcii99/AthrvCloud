//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Card struct
typedef struct {
    char suit[10];
    char value[5];
} Card;

// Function to create a deck of cards
void createDeck(Card *deck) {
    char values[][5] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char suits[][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int counter = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card;
            strcpy(card.suit, suits[i]);
            strcpy(card.value, values[j]);
            deck[counter++] = card;
        }
    }
}

// Function to shuffle the deck of cards
void shuffleDeck(Card *deck) {
    srand(time(NULL));
    
    for (int i = 0; i < 52; i++) {
        int index = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;
    }
}

// Function to draw cards from the deck
void drawCards(Card *deck, int numCards, Card *hand) {
    for (int i = 0; i < numCards; i++) {
        hand[i] = deck[i];
    }
}

// Function to print a card
void printCard(Card card) {
    printf("%s of %s\n", card.value, card.suit);
}

// Function to print a hand of cards
void printHand(Card *hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(hand[i]);
    }
}

int main() {
    Card deck[52];
    createDeck(deck);
    shuffleDeck(deck);
    
    Card playerHand[5];
    drawCards(deck, 5, playerHand);
    
    printf("Your hand:\n");
    printHand(playerHand, 5);
    
    return 0;
}