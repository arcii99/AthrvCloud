//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

enum Suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

struct Card {
    enum Suit suit;
    enum Rank rank;
};

// Function to initialize deck of cards
void initializeDeck(struct Card *deck) {
    int cardIndex = 0;
    for(int i = HEARTS; i <= SPADES; i++) {
        for(int j = ACE; j <= KING; j++) {
            deck[cardIndex].suit = i;
            deck[cardIndex].rank = j;
            cardIndex++;
        }
    }
}

// Function to shuffle deck of cards
void shuffleDeck(struct Card *deck) {
    srand(time(NULL));
    for(int i = 0; i < DECK_SIZE - 1; i++) {
        int j = rand() % DECK_SIZE;
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the contents of a card
void printCard(struct Card card) {
    switch(card.rank) {
    case ACE:
        printf("A");
        break;
    case TWO:
        printf("2");
        break;
    case THREE:
        printf("3");
        break;
    case FOUR:
        printf("4");
        break;
    case FIVE:
        printf("5");
        break;
    case SIX:
        printf("6");
        break;
    case SEVEN:
        printf("7");
        break;
    case EIGHT:
        printf("8");
        break;
    case NINE:
        printf("9");
        break;
    case TEN:
        printf("10");
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
    }
    switch(card.suit) {
    case HEARTS:
        printf("H ");
        break;
    case DIAMONDS:
        printf("D ");
        break;
    case CLUBS:
        printf("C ");
        break;
    case SPADES:
        printf("S ");
        break;
    }
}

// Function to print the contents of a hand
void printHand(struct Card *hand, int size) {
    for(int i = 0; i < size; i++) {
        printCard(hand[i]);
    }
}

// Function to evaluate the value of a hand
int evaluateHand(struct Card *hand, int size) {
    int pair = 0;
    int threeOfaKind = 0;
    int fourOfaKind = 0;
    int flush = 1;
    int straight = 1;
    int royalFlush = 0;
    int straightFlush = 0;
    for(int i = 0; i < size - 1; i++) {
        if(hand[i].rank == hand[i+1].rank - 1) {
            straight++;
        }
        if(hand[i].suit != hand[i+1].suit) {
            flush = 0;
        }
        if(i < size - 3 && hand[i].rank == hand[i+1].rank && hand[i+1].rank == hand[i+2].rank && hand[i+2].rank == hand[i+3].rank) {
            fourOfaKind = 1;
        }
        if(i < size - 2 && hand[i].rank == hand[i+1].rank && hand[i+1].rank == hand[i+2].rank) {
            threeOfaKind = 1;
            if(i > 0 && hand[i-1].rank == hand[i].rank || i < size - 3 && hand[i+2].rank == hand[i+3].rank) {
                threeOfaKind = 0;
            }
        }
        if(i < size - 1 && hand[i].rank == hand[i+1].rank) {
            pair++;
        }
    }
    if(straight == 5) {
        if(hand[0].rank == ACE) {
            royalFlush = 1;
        }
        straightFlush = 1;
    }
    if(flush && straightFlush) {
        return royalFlush ? 10 : 9;
    }
    if(fourOfaKind) {
        return 8;
    }
    if(threeOfaKind && pair) {
        return 7;
    }
    if(flush) {
        return 6;
    }
    if(straight) {
        return 5;
    }
    if(threeOfaKind) {
        return 4;
    }
    if(pair == 2) {
        return 3;
    }
    if(pair) {
        return 2;
    }
    return 1;
}

int main() {
    struct Card deck[DECK_SIZE];
    initializeDeck(deck);
    shuffleDeck(deck);
    printf("Deck: ");
    printHand(deck, DECK_SIZE);
    printf("\n\n");
    struct Card hand[HAND_SIZE];
    for(int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    printf("Hand: ");
    printHand(hand, HAND_SIZE);
    printf("\nValue: %d\n", evaluateHand(hand, HAND_SIZE));
    return 0;
}