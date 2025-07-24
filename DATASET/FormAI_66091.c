//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for card suits
#define HEARTS 0
#define DIAMONDS 1
#define CLUBS 2
#define SPADES 3

// Define constants for card values
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// Define structure for a card
typedef struct {
    int suit;     // 0 = hearts, 1 = diamonds, 2 = clubs, 3 = spades
    int value;    // 1 = ace, 2-10 = 2-10, 11 = jack, 12 = queen, 13 = king
} Card;

// Define functions for creating and printing a card
void printCard(Card c) {
    switch (c.value) {
        case ACE:
            printf("Ace");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
        default:
            printf("%d", c.value);
            break;
    }

    printf(" of ");

    switch (c.suit) {
        case HEARTS:
            printf("Hearts");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case CLUBS:
            printf("Clubs");
            break;
        case SPADES:
            printf("Spades");
            break;
    }
}

Card createCard(int suit, int value) {
    Card c;
    c.suit = suit;
    c.value = value;
    return c;
}

// Define function for shuffling a deck of cards
void shuffleDeck(Card *deck, int size) {
    int i, j;
    Card temp;
    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int i, j;
    int numPlayers;
    Card deck[52];
    int playerHands[10][5]; // max of 10 players, each with a hand of 5 cards
    int playerScores[10];
    int winner;
    srand(time(NULL)); // seed the random number generator

    // Create a deck of cards
    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            deck[i * 13 + j - 1] = createCard(i, j);
        }
    }

    // Shuffle the deck
    shuffleDeck(deck, 52);

    // Prompt the user to enter the number of players
    do {
        printf("Enter the number of players (2-10): ");
        scanf("%d", &numPlayers);
    } while (numPlayers < 2 || numPlayers > 10);

    // Deal the cards to the players
    for (i = 0; i < 5; i++) {
        for (j = 0; j < numPlayers; j++) {
            playerHands[j][i] = deck[numPlayers * i + j].value;
        }
    }

    // Calculate the score for each player
    for (i = 0; i < numPlayers; i++) {
        playerScores[i] = 0;
        for (j = 0; j < 5; j++) {
            if (playerHands[i][j] >= 10) {
                playerScores[i] += 10;
            } else if (playerHands[i][j] == ACE) {
                playerScores[i] += 11;
            } else {
                playerScores[i] += playerHands[i][j];
            }
        }

        if (playerScores[i] > 21) {
            playerScores[i] = 0; // bust
        }
    }

    // Determine the winner
    winner = 0;
    for (i = 1; i < numPlayers; i++) {
        if (playerScores[i] > playerScores[winner]) {
            winner = i;
        }
    }

    // Print the players' hands and scores
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d's hand: ", i+1);
        for (j = 0; j < 5; j++) {
            printCard(createCard(0, playerHands[i][j]));
            printf(", ");
        }
        printf("\n");
        printf("Player %d's score: %d\n", i+1, playerScores[i]);
    }

    // Print the winner
    printf("Player %d wins!\n", winner+1);

    return 0;
}