//FormAI DATASET v1.0 Category: Poker Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

typedef struct {
    int rank;
    int suit;
} Card;

void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;

    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void printCard(Card c) {
    const char *rankNames[NUM_RANKS] =
            {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    const char *suitNames[NUM_SUITS] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    printf("%s of %s", rankNames[c.rank], suitNames[c.suit]);
}

void printHand(Card *hand, int numCards) {
    int i;

    for (i = 0; i < numCards; i++) {
        printCard(hand[i]);
        printf("\n");
    }
}

int rankBySuit(const void *v1, const void *v2) {
    const Card *c1 = (const Card *) v1;
    const Card *c2 = (const Card *) v2;

    if (c1->suit < c2->suit)
        return -1;
    else if (c1->suit > c2->suit)
        return 1;
    else if (c1->rank < c2->rank)
        return -1;
    else if (c1->rank > c2->rank)
        return 1;
    else
        return 0;
}

int rankByRank(const void *v1, const void *v2) {
    const Card *c1 = (const Card *) v1;
    const Card *c2 = (const Card *) v2;

    if (c1->rank < c2->rank)
        return -1;
    else if (c1->rank > c2->rank)
        return 1;
    else if (c1->suit < c2->suit)
        return -1;
    else if (c1->suit > c2->suit)
        return 1;
    else
        return 0;
}

int isFlush(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankBySuit);

    int i;

    for (i = 1; i < numCards; i++) {
        if (hand[i].suit != hand[i - 1].suit)
            return 0;
    }

    return 1;
}

int isStraight(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    int i;

    for (i = 1; i < numCards; i++) {
        if (hand[i].rank != hand[i - 1].rank + 1)
            return 0;
    }

    return 1;
}

int isStraightFlush(Card *hand, int numCards) {
    return isFlush(hand, numCards) && isStraight(hand, numCards);
}

int isFourOfAKind(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    return (hand[0].rank == hand[1].rank &&
            hand[1].rank == hand[2].rank &&
            hand[2].rank == hand[3].rank) ||
           (hand[1].rank == hand[2].rank &&
            hand[2].rank == hand[3].rank &&
            hand[3].rank == hand[4].rank);
}

int isFullHouse(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    return (hand[0].rank == hand[1].rank &&
            hand[2].rank == hand[3].rank &&
            hand[3].rank == hand[4].rank) ||
           (hand[0].rank == hand[1].rank &&
            hand[1].rank == hand[2].rank &&
            hand[3].rank == hand[4].rank);
}

int isThreeOfAKind(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    return (hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank) ||
           (hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank) ||
           (hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank);
}

int isTwoPair(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    return (hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) ||
           (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank) ||
           (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank);
}

int isOnePair(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), rankByRank);

    return hand[0].rank == hand[1].rank ||
           hand[1].rank == hand[2].rank ||
           hand[2].rank == hand[3].rank ||
           hand[3].rank == hand[4].rank;
}

int getRanking(Card *hand, int numCards) {
    if (isStraightFlush(hand, numCards))
        return 9;
    else if (isFourOfAKind(hand, numCards))
        return 8;
    else if (isFullHouse(hand, numCards))
        return 7;
    else if (isFlush(hand, numCards))
        return 6;
    else if (isStraight(hand, numCards))
        return 5;
    else if (isThreeOfAKind(hand, numCards))
        return 4;
    else if (isTwoPair(hand, numCards))
        return 3;
    else if (isOnePair(hand, numCards))
        return 2;
    else
        return 1;
}

int main() {
    Card deck[NUM_CARDS];
    Card playerHand[HAND_SIZE];
    Card computerHand[HAND_SIZE];
    int playerRank, computerRank, i;

    srand(time(NULL));

    // Initialize the deck of cards
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].rank = i % NUM_RANKS;
        deck[i].suit = i / NUM_RANKS;
    }

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal the cards
    for (i = 0; i < HAND_SIZE; i++) {
        playerHand[i] = deck[i];
        computerHand[i] = deck[HAND_SIZE + i];
    }

    // Determine the rankings of each hand
    playerRank = getRanking(playerHand, HAND_SIZE);
    computerRank = getRanking(computerHand, HAND_SIZE);

    // Print out the hands
    printf("Your hand:\n");
    printHand(playerHand, HAND_SIZE);
    printf("\n");

    printf("Computer's hand:\n");
    printHand(computerHand, HAND_SIZE);
    printf("\n");

    // Determine the winner
    if (playerRank > computerRank) {
        printf("You win!\n");
    } else if (computerRank > playerRank) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}