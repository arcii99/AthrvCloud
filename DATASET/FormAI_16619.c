//FormAI DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4 // Number of players in the game
#define NUM_CARDS 52 // Number of cards in the deck
#define HAND_SIZE 2 // Number of cards each player has in their hand

struct Card {
    char suit;
    int value;
};

struct Player {
    char name[20];
    struct Card hand[HAND_SIZE];
};

void initializeDeck(struct Card deck[]) {
    int i, j, index = 0;
    char suits[] = {'C', 'D', 'H', 'S'};

    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            deck[index].suit = suits[i];
            deck[index].value = j;
            index++;
        }
    }
}

void shuffleDeck(struct Card deck[]) {
    int i, j;
    struct Card temp;

    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(struct Card deck[], struct Player players[]) {
    int i, j, index = 0;

    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[index];
            index++;
        }
    }
}

void printHand(struct Card hand[]) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        printf("%c%d ", hand[i].suit, hand[i].value);
    }

    printf("\n");
}

void printPlayerHands(struct Player players[]) {
    int i;

    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's hand: ", players[i].name);
        printHand(players[i].hand);
    }
}

void playGame(struct Card deck[], struct Player players[]) {
    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, players);

    printf("Dealing cards...\n");
    printPlayerHands(players);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    struct Card deck[NUM_CARDS];
    struct Player players[NUM_PLAYERS] = {
        {"Player 1"},
        {"Player 2"},
        {"Player 3"},
        {"Player 4"}
    };

    playGame(deck, players);

    return 0;
}