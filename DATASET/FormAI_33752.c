//FormAI DATASET v1.0 Category: Poker Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS_PER_SUIT 13
#define TOTAL_SUITS 4
#define TOTAL_CARDS (CARDS_PER_SUIT * TOTAL_SUITS)

typedef enum {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} Suit;

typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Value;

typedef struct {
    Suit suit;
    Value value;
} Card;

void shuffleDeck(Card *deck);
void printDeck(Card *deck);
void dealHands(Card *deck, Card *playerHand, Card *computerHand);

int main() {
    Card deck[TOTAL_CARDS];
    Card playerHand[5];
    Card computerHand[5];

    srand(time(NULL));

    // initialize the deck
    int cardCount = 0;
    for (int i = 0; i < TOTAL_SUITS; i++) {
        for (int j = 2; j <= ACE; j++) {
            Card card = { i, j };
            deck[cardCount++] = card;
        }
    }

    // shuffle the deck
    shuffleDeck(deck);

    // deal hands
    dealHands(deck, playerHand, computerHand);

    // print hands
    printf("Player hand:\n");
    printDeck(playerHand);

    printf("\nComputer hand:\n");
    printDeck(computerHand);

    return 0;
}

void shuffleDeck(Card *deck) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int j = rand() % TOTAL_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card card) {
    const char *suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char *values[] = { "", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    printf("%s of %s", values[card.value], suits[card.suit]);
}

void printDeck(Card *deck) {
    for (int i = 0; i < 5; i++) {
        printCard(deck[i]);
        printf("\n");
    }
}

void dealHands(Card *deck, Card *playerHand, Card *computerHand) {
    for (int i = 0; i < 5; i++) {
        playerHand[i] = deck[i * 2];
        computerHand[i] = deck[(i * 2) + 1];
    }
}