//FormAI DATASET v1.0 Category: Poker Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum { 
    DIAMONDS,
    CLUBS,
    HEARTS,
    SPADES
} Suit;

typedef struct {
    Suit suit;
    int value;
} Card;

void shuffleDeck(Card* deck) {
    srand(time(NULL));
    for(int i = DECK_SIZE - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void printCard(Card card) {
    char suitChar = '?';
    switch(card.suit) {
        case DIAMONDS:
            suitChar = 'D';
            break;
        case CLUBS:
            suitChar = 'C';
            break;
        case HEARTS:
            suitChar = 'H';
            break;
        case SPADES:
            suitChar = 'S';
            break;
    }
    printf("%c%d ", suitChar, card.value);
}

void printHand(Card* hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

int rankHand(Card* hand) {
    int rank[13] = {0};
    int suit[4] = {0};

    int pairs = 0;
    int threeOfAKind = 0;
    int fourOfAKind = 0;

    int straight = 0;
    int flush = 0;

    // count cards per value and suit
    for(int i = 0; i < HAND_SIZE; i++) {
        rank[hand[i].value - 1]++;
        suit[hand[i].suit]++;
    }

    // check for pairs, three of a kind, and four of a kind
    for(int i = 0; i < 13; i++) {
        if(rank[i] == 2) {
            pairs++;
        } else if(rank[i] == 3) {
            threeOfAKind++;
        } else if(rank[i] == 4) {
            fourOfAKind++;
        }
    }

    // check for flush
    for(int i = 0; i < 4; i++) {
        if(suit[i] == HAND_SIZE) {
            flush = 1;
            break;
        }
    }

    // check for straight
    for(int i = 0; i <= 9; i++) {
        if(rank[i] == 1 && rank[i+1] == 1 && rank[i+2] == 1 && rank[i+3] == 1 && rank[i+4] == 1) {
            straight = 1;
            break;
        }
    }

    // determine the hand's rank
    if(straight && flush) {
        return 9; // straight flush
    } else if(fourOfAKind > 0) {
        return 8; // four of a kind
    } else if(threeOfAKind > 0 && pairs > 0) {
        return 7; // full house
    } else if(flush) {
        return 6; // flush
    } else if(straight) {
        return 5; // straight
    } else if(threeOfAKind > 0) {
        return 4; // three of a kind
    } else if(pairs == 2) {
        return 3; // two pair
    } else if(pairs == 1) {
        return 2; // one pair
    } else {
        return 1; // high card
    }
}

int main() {
    Card deck[DECK_SIZE] = {
        { DIAMONDS, 1 }, { DIAMONDS, 2 }, { DIAMONDS, 3 }, { DIAMONDS, 4 }, { DIAMONDS, 5 }, { DIAMONDS, 6 }, { DIAMONDS, 7 },
        { DIAMONDS, 8 }, { DIAMONDS, 9 }, { DIAMONDS, 10 }, { DIAMONDS, 11 }, { DIAMONDS, 12 }, { DIAMONDS, 13 },
        { CLUBS, 1 }, { CLUBS, 2 }, { CLUBS, 3 }, { CLUBS, 4 }, { CLUBS, 5 }, { CLUBS, 6 }, { CLUBS, 7 },
        { CLUBS, 8 }, { CLUBS, 9 }, { CLUBS, 10 }, { CLUBS, 11 }, { CLUBS, 12 }, { CLUBS, 13 },
        { HEARTS, 1 }, { HEARTS, 2 }, { HEARTS, 3 }, { HEARTS, 4 }, { HEARTS, 5 }, { HEARTS, 6 }, { HEARTS, 7 },
        { HEARTS, 8 }, { HEARTS, 9 }, { HEARTS, 10 }, { HEARTS, 11 }, { HEARTS, 12 }, { HEARTS, 13 },
        { SPADES, 1 }, { SPADES, 2 }, { SPADES, 3 }, { SPADES, 4 }, { SPADES, 5 }, { SPADES, 6 }, { SPADES, 7 },
        { SPADES, 8 }, { SPADES, 9 }, { SPADES, 10 }, { SPADES, 11 }, { SPADES, 12 }, { SPADES, 13 }
    };

    shuffleDeck(deck);

    Card playerHand[HAND_SIZE];
    Card dealerHand[HAND_SIZE];

    for(int i = 0; i < HAND_SIZE; i++) {
        playerHand[i] = deck[i];
        dealerHand[i] = deck[i + HAND_SIZE];
    }

    printf("Player hand: ");
    printHand(playerHand);

    printf("Dealer hand: ");
    printHand(dealerHand);

    int playerRank = rankHand(playerHand);
    int dealerRank = rankHand(dealerHand);

    if(playerRank > dealerRank) {
        printf("Player wins with rank %d\n", playerRank);
    } else if(dealerRank > playerRank) {
        printf("Dealer wins with rank %d\n", dealerRank);
    } else {
        printf("It's a tie with rank %d\n", playerRank);
    }

    return 0;
}