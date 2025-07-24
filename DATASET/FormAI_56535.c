//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define SUITS 4
#define RANKS 13

typedef struct {
    int rank;
    char *suit;
} Card;

// Function that generates a shuffled deck of Cards
int generateDeck(Card *deck) {
    int i, j, count = 0;
    char *suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    srand(time(NULL));

    for (i = 0; i < SUITS; i++) {
        for (j = 1; j <= RANKS; j++) {
            deck[count].rank = j;
            deck[count].suit = suits[i];
            count++;
        }
    }
    // Shuffle the deck
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    return count;
}

// Function that displays the hand of cards
void displayHand(Card *hand, int numCards) {
    int i;
    printf("\nYour hand:\n");
    for (i = 0; i < numCards; i++) {
        printf("%d of %s\n", hand[i].rank, hand[i].suit);
    }
}

// Function that sorts the hand of cards
void sortHand(Card *hand, int numCards) {
    int i, j;
    Card temp;
    for (i = 0; i < numCards; i++) {
        for (j = i+1; j < numCards; j++) {
            if (hand[i].rank > hand[j].rank) {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int main() {
    Card deck[MAX_CARDS];
    Card playerHand[5];
    int numCards = generateDeck(deck), i;
    char answer;

    printf("Welcome to C Poker!\n");
    printf("Would you like to deal a hand? (y/n)\n");
    scanf("%c", &answer);

    if (answer == 'y') {
        // Deal hand
        for (i = 0; i < 5; i++) {
            playerHand[i] = deck[i];
        }
        displayHand(playerHand, 5);
        // Sort hand
        sortHand(playerHand, 5);
        printf("\nYour sorted hand:\n");
        displayHand(playerHand, 5);
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}