//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define NUM_CARDS_PER_PLAYER 5

typedef struct card {
    char suit;
    char face;
} Card;

void shuffleDeck(Card *deck) {
    srand(time(NULL));
    for(int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(Card *deck, int numCards) {
    for(int i = 0; i < numCards; i++) {
        printf("%c%c ", deck[i].face, deck[i].suit);
    }
}

void printHand(Card *hand, int numCards) {
    for(int i = 0; i < numCards; i++) {
        printf("%c%c ", hand[i].face, hand[i].suit);
    }
}

int compareCards(const void *card1, const void *card2) {
    Card *c1 = (Card *)card1;
    Card *c2 = (Card *)card2;
    return c1->face - c2->face;
}

void dealHands(Card *deck, Card **hands, int numCardsPerHand, int numPlayers) {
    for(int i = 0; i < numPlayers; i++) {
        for(int j = 0; j < numCardsPerHand; j++) {
            hands[i][j] = deck[i * numCardsPerHand + j];
        }
        qsort(hands[i], numCardsPerHand, sizeof(Card), compareCards);
    }
}

void printWinner(Card **hands, int numCardsPerHand, int numPlayers) {
    int bestHandScore = -1, winner = -1;
    for(int i = 0; i < numPlayers; i++) {
        int score = 0;
        for(int j = 0; j < numCardsPerHand; j++) {
            score += hands[i][j].face;
        }
        if(score > bestHandScore) {
            bestHandScore = score;
            winner = i;
        }
    }
    printf("Player %d wins with a score of %d\n", winner + 1, bestHandScore);
}

int main() {
    Card deck[NUM_CARDS];
    for(int i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = i / 13;
        switch(i % 13) {
            case 0:
                deck[i].face = 'A';
                break;
            case 9:
                deck[i].face = 'T';
                break;
            case 10:
                deck[i].face = 'J';
                break;
            case 11:
                deck[i].face = 'Q';
                break;
            case 12:
                deck[i].face = 'K';
                break;
            default:
                deck[i].face = ((i % 13) + 1) + '0';
                break;
        }
    }

    shuffleDeck(deck);

    Card *hands[NUM_PLAYERS];
    for(int i = 0; i < NUM_PLAYERS; i++) {
        hands[i] = malloc(NUM_CARDS_PER_PLAYER * sizeof(Card));
    }

    dealHands(deck, hands, NUM_CARDS_PER_PLAYER, NUM_PLAYERS);

    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand: ", i + 1);
        printHand(hands[i], NUM_CARDS_PER_PLAYER);
        printf("\n");
    }

    printWinner(hands, NUM_CARDS_PER_PLAYER, NUM_PLAYERS);

    for(int i = 0; i < NUM_PLAYERS; i++) {
        free(hands[i]);
    }

    return 0;
}