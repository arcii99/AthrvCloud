//FormAI DATASET v1.0 Category: Poker Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

#define PLAYER_HAND_SIZE 2
#define TABLE_SIZE 5
#define NUM_PLAYERS 2

int deck[NUM_CARDS];
int playerHands[NUM_PLAYERS][PLAYER_HAND_SIZE];
int tableCards[TABLE_SIZE];

void shuffleDeck() {
    int i, temp, r;
    for(i = 0; i < NUM_CARDS; i++) {
        deck[i] = i; 
    }

    for(i = 0; i < NUM_CARDS; i++) {
        r = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void printCards(int * cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        int rank = cards[i] % NUM_RANKS;
        int suit = cards[i] / NUM_RANKS;
        switch(rank) {
            case 0:
                printf("Ace");
                break;
            case 10:
                printf("Jack");
                break;
            case 11:
                printf("Queen");
                break;
            case 12:
                printf("King");
                break;
            default:
                printf("%d", rank + 1);
        }
        printf(" of ");
        switch(suit) {
            case 0:
                printf("Hearts");
                break;
            case 1:
                printf("Diamonds");
                break;
            case 2:
                printf("Clubs");
                break;
            case 3:
                printf("Spades");
                break;
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    shuffleDeck();

    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        for(int j = 0; j < PLAYER_HAND_SIZE; j++) {
            playerHands[i][j] = deck[i * PLAYER_HAND_SIZE + j];
        }
        printCards(playerHands[i], PLAYER_HAND_SIZE);
        printf("\n");
    }

    printf("Table cards:\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        tableCards[i] = deck[NUM_PLAYERS * PLAYER_HAND_SIZE + i];
    }
    printCards(tableCards, TABLE_SIZE);

    return 0;
}