//FormAI DATASET v1.0 Category: Poker Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure for deck of cards
typedef struct {
    char suit[9];
    char value[6];
    int rank;
} card;

//Function to initialize deck of cards
void initializeDeck(card deck[]) {
    char suits[4][9] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    char values[13][6] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int rank = 1;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            deck[rank-1].rank = rank;
            strcpy(deck[rank-1].suit, suits[i]);
            strcpy(deck[rank-1].value, values[j]);
            rank++;
        }
    }
}

//Function to shuffle deck of cards
void shuffleDeck(card deck[], int size) {
    srand(time(NULL));
    for(int i = size-1; i >= 1; i--) {
        int j = rand()%(i+1);
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//Function to deal cards to a player (hand)
void dealCards(card deck[], card hand[], int numCards) {
    for(int i = 0; i < numCards; i++) {
        hand[i] = deck[i];
    }
}

//Function to print a player's hand
void printHand(card hand[], int numCards) {
    for(int i = 0; i < numCards; i++) {
        printf("%s of %s\n", hand[i].value, hand[i].suit);
    }
}

int main() {
    card deck[52];
    card playerHand[5];
    initializeDeck(deck);
    shuffleDeck(deck, 52);

    printf("Welcome to the jolly game of Poker, my dear Watson.\n");
    printf("You will be playing against the computer, who is quite a formidable opponent.\n");
    printf("Let's begin the game!\n");

    for(int i = 0; i < 5; i++) {
        printf("Your cards are:\n");
        dealCards(deck, playerHand, 5);
        printHand(playerHand, 5);
        printf("It is your turn to make a move. What would you like to do? (fold/bet/check)\n");
        char move[10];
        scanf("%s", move);
        printf("You chose to %s\n", move);
    }

    printf("Thank you for playing, my dear friend. Until next time!\n");
    return 0;
}