//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};

struct Card {
    enum Rank rank;
    enum Suit suit;
};

void printCard(struct Card card) {
    switch (card.rank) {
        case ACE:
            printf("A");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        default:
            printf("%d", card.rank);
    }

    switch (card.suit) {
        case HEARTS:
            printf("\u2665 ");
            break;
        case DIAMONDS:
            printf("\u2666 ");
            break;
        case CLUBS:
            printf("\u2663 ");
            break;
        case SPADES:
            printf("\u2660 ");
            break;
    }
}

void printCards(struct Card deck[], int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(deck[i]);
    }
    printf("\n");
}

void shuffleDeck(struct Card deck[], int size) {
    srand(time(NULL));  // Initialize random seed

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Pick random index smaller than i
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    struct Card deck[52];  // 52 cards in a standard deck
    int cardNum = 0;

    // Generate deck
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            struct Card card = {i, j};
            deck[cardNum] = card;
            cardNum++;
        }
    }

    shuffleDeck(deck, 52);

    // Deal two cards to each player
    struct Card player1[2];
    player1[0] = deck[0];
    player1[1] = deck[1];
    printf("Player 1's cards: ");
    printCards(player1, 2);

    struct Card player2[2];
    player2[0] = deck[2];
    player2[1] = deck[3];
    printf("Player 2's cards: ");
    printCards(player2, 2);

    return 0;
}