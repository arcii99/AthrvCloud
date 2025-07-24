//FormAI DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

typedef struct {
    int value;
    int suit;
} Card;

void printCard(Card card) {
    printf("%2s of %-8s", values[card.value], suits[card.suit]);
}

void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;

    srand(time(NULL));

    for(i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printHand(Card *hand, int numCards) {
    int i;
    for(i = 0; i < numCards; i++) {
        printCard(hand[i]);
        printf("\n");
    }
}

int compareCards(const void *a, const void *b) {
    const Card *c1 = (const Card *)a;
    const Card *c2 = (const Card *)b;

    return (c1->value - c2->value);
}

int isFlush(Card *hand, int numCards) {
    int i;
    int suit = hand[0].suit;

    for(i = 1; i < numCards; i++) {
        if(hand[i].suit != suit) {
            return 0;
        }
    }

    return 1;
}

int isStraight(Card *hand, int numCards) {
    int i;
    qsort(hand, numCards, sizeof(Card), compareCards);

    for(i = 1; i < numCards; i++) {
        if(hand[i].value != hand[i-1].value + 1) {
            return 0;
        }
    }

    return 1;
}

int evaluateHand(Card *hand, int numCards) {
    if(isFlush(hand, numCards) && isStraight(hand, numCards)) {
        return 9; // Straight Flush
    }

    if(hand[0].value == hand[3].value || hand[1].value == hand[4].value) {
        return 8; // Four of a Kind
    }

    if(hand[0].value == hand[2].value && hand[3].value == hand[4].value ||
        hand[0].value == hand[1].value && hand[2].value == hand[4].value) {
        return 7; // Full House
    }

    if(isFlush(hand, numCards)) {
        return 6; // Flush
    }

    if(isStraight(hand, numCards)) {
        return 5; // Straight
    }

    if(hand[0].value == hand[2].value || hand[1].value == hand[3].value || 
        hand[2].value == hand[4].value) {
        return 4; // Three of a Kind
    }

    if(hand[0].value == hand[1].value && hand[2].value == hand[3].value ||
        hand[0].value == hand[1].value && hand[3].value == hand[4].value ||
        hand[1].value == hand[2].value && hand[3].value == hand[4].value) {
        return 3; // Two Pair
    }

    if(hand[0].value == hand[1].value || hand[1].value == hand[2].value || 
        hand[2].value == hand[3].value || hand[3].value == hand[4].value) {
        return 2; // One Pair
    }

    return 1; // High Card
}

int main(void) {
    int i, j;
    Card deck[52];
    Card hand[5];

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 13; j++) {
            deck[i*13+j].value = j;
            deck[i*13+j].suit = i;
        }
    }

    shuffleDeck(deck);

    printf("Dealing hand...\n");
    for(i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    printf("Hand:\n");
    printHand(hand, 5);

    printf("\nRank: %d\n", evaluateHand(hand, 5));

    return 0;
}