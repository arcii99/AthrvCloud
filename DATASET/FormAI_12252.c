//FormAI DATASET v1.0 Category: Poker Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define NUM_RANKS 13
#define NUM_SUITS 4

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
} Player;

void shuffleDeck(Card deck[]) {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player* players, int numPlayers, Card deck[]) {
    int currentCard = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < numPlayers; j++) {
            players[j].hand[i] = deck[currentCard];
            currentCard++;
        }
    }
}

void printCard(Card card) {
    char suit;
    if (card.suit == 0) {
        suit = 'C';
    } else if (card.suit == 1) {
        suit = 'D';
    } else if (card.suit == 2) {
        suit = 'H';
    } else {
        suit = 'S';
    }

    if (card.rank == 1) {
        printf("A%c ", suit);
    } else if (card.rank == 10) {
        printf("T%c ", suit);
    } else if (card.rank == 11) {
        printf("J%c ", suit);
    } else if (card.rank == 12) {
        printf("Q%c ", suit);
    } else if (card.rank == 13) {
        printf("K%c ", suit);
    } else {
        printf("%d%c ", card.rank, suit);
    }
}

void printHand(Player player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(player.hand[i]);
    }
    printf("\n");
}

int compareCards(const void* a, const void* b) {
    Card* cardA = (Card*)a;
    Card* cardB = (Card*)b;
    return cardB->rank - cardA->rank;
}

int isFlush(Card hand[]) {
    int suit = hand[0].suit;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int isStraight(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].rank != hand[i - 1].rank - 1) {
            return 0;
        }
    }
    return 1;
}

int isStraightFlush(Card hand[]) {
    return isFlush(hand) && isStraight(hand);
}

int isFourOfAKind(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    if (hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank) {
        return 1;
    }
    return 0;
}

int isFullHouse(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    if (hand[0].rank == hand[1].rank && hand[2].rank == hand[4].rank) {
        return 1;
    }
    if (hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank) {
        return 1;
    }
    return 0;
}

int isThreeOfAKind(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    if (hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank || hand[2].rank == hand[4].rank) {
        return 1;
    }
    return 0;
}

int isTwoPair(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    if (hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) {
        return 1;
    }
    if (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank) {
        return 1;
    }
    if (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank) {
        return 1;
    }
    return 0;
}

int isPair(Card hand[]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i].rank == hand[i + 1].rank) {
            return 1;
        }
    }
    return 0;
}

int getRank(Card hand[]) {
    if (isStraightFlush(hand)) {
        return 9;
    }
    if (isFourOfAKind(hand)) {
        return 8;
    }
    if (isFullHouse(hand)) {
        return 7;
    }
    if (isFlush(hand)) {
        return 6;
    }
    if (isStraight(hand)) {
        return 5;
    }
    if (isThreeOfAKind(hand)) {
        return 4;
    }
    if (isTwoPair(hand)) {
        return 3;
    }
    if (isPair(hand)) {
        return 2;
    }
    return 1;
}

void playGame(Player* players, int numPlayers, Card deck[]) {
    shuffleDeck(deck);
    dealCards(players, numPlayers, deck);
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's hand: ", i + 1);
        printHand(players[i]);
        printf("Player %d's rank: %d\n", i + 1, getRank(players[i].hand));
    }
}

int main() {
    Card deck[DECK_SIZE];
    int currentCard = 0;
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[currentCard].rank = i + 1;
            deck[currentCard].suit = j;
            currentCard++;
        }
    }
    Player players[2];
    playGame(players, 2, deck);
    return 0;
}