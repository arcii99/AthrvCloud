//FormAI DATASET v1.0 Category: Poker Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define PLAYER_HAND_SIZE 5

const char *CARDS[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

const char *SUITS[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

int deck[DECK_SIZE];
int playerHand[PLAYER_HAND_SIZE];

void shuffleDeck() {
    srand(time(NULL));

    for (int i = 0; i < DECK_SIZE; i++) {
        int randomIndex = rand() % DECK_SIZE;
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void printDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        printf("%s of %s\n", CARDS[deck[i] % 13], SUITS[deck[i] / 13]);
    }
}

void dealCards() {
    for (int i = 0; i < PLAYER_HAND_SIZE; i++) {
        playerHand[i] = deck[i];
    }
}

void printHand() {
    printf("Your hand:\n");
    for (int i = 0; i < PLAYER_HAND_SIZE; i++) {
        printf("%s of %s\n", CARDS[playerHand[i] % 13], SUITS[playerHand[i] / 13]);
    }
}

int checkHand() {
    int pairs = 0;
    int triples = 0;
    int quads = 0;
    int flush = 0;
    int straight = 0;

    // Check for pairs, triples, and quads
    for (int i = 0; i < PLAYER_HAND_SIZE; i++) {
        int cardValue = playerHand[i] % 13;

        int count = 0;
        for (int j = 0; j < PLAYER_HAND_SIZE; j++) {
            if (playerHand[j] % 13 == cardValue) {
                count++;
            }
        }

        if (count == 2) {
            pairs++;
        } else if (count == 3) {
            triples++;
        } else if (count == 4) {
            quads++;
        }
    }

    // Check for flush
    for (int i = 1; i < PLAYER_HAND_SIZE; i++) {
        if (playerHand[i] / 13 != playerHand[0] / 13) {
            flush = 0;
            break;
        }
        flush = 1;
    }

    // Check for straight
    int straightFound = 0;
    int i = 0;
    while (i < PLAYER_HAND_SIZE - 1) {
        if ((playerHand[i] % 13) + 1 == playerHand[i+1] % 13) {
            straight++;
        } else {
            straight = 0;
        }

        if (straight == 4) {
            straightFound = 1;
            break;
        }

        i++;
    }

    if (pairs == 1 && triples == 0 && quads == 0) {
        printf("Pair\n");
        return 1;
    } else if (pairs == 0 && triples == 1 && quads == 0) {
        printf("Three of a kind\n");
        return 1;
    } else if (pairs == 1 && triples == 1 && quads == 0) {
        printf("Full house\n");
        return 1;
    } else if (pairs == 0 && triples == 0 && quads == 1) {
        printf("Four of a kind\n");
        return 1;
    } else if (flush == 1) {
        printf("Flush\n");
        return 1;
    } else if (straightFound == 1) {
        printf("Straight\n");
        return 1;
    } else {
        printf("High card\n");
        return 0;
    }
}

int main() {
    // Initialize deck
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }

    shuffleDeck();
    //printDeck();

    dealCards();
    printHand();

    checkHand();

    return 0;
}