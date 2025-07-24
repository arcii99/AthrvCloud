//FormAI DATASET v1.0 Category: Poker Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {
    CLUB, DIAMOND, HEART, SPADE
} Suit;

typedef struct {
    Suit suit;
    int rank;
} Card;

char* suitNames[] = {"Club", "Diamond", "Heart", "Spade"};
char* rankNames[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

int aceHigh(const void* a, const void* b) {
    const Card* card1 = a;
    const Card* card2 = b;
    return (card2->rank - card1->rank);
}

int main() {
    int i, j, k, l, m;
    int score = 0;
    int rankCount[13] = {0};
    int suitCount[4] = {0};
    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];

    // Populate deck of cards
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[i * 13 + j].suit = i;
            deck[i * 13 + j].rank = j;
        }
    }

    // Shuffle deck of cards
    srand((unsigned int) time(NULL));
    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal cards
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // Sort cards in hand
    qsort(hand, HAND_SIZE, sizeof(Card), &aceHigh);

    // Check for flush
    for (i = 0; i < HAND_SIZE; i++) {
        suitCount[hand[i].suit]++;
    }

    for (i = 0; i < 4; i++) {
        if (suitCount[i] == HAND_SIZE) {
            printf("You have a flush!\n");
            score += 1000;
            break;
        }
    }

    // Check for straight
    for (i = 0; i < HAND_SIZE; i++) {
        rankCount[hand[i].rank]++;
    }

    if (rankCount[0] && rankCount[1] && rankCount[2] && rankCount[3] && rankCount[12]) { // Ace, Two, Three, Four, Five
        printf("You have a straight!\n");
        score += 800;
    } else {
        for (i = 0; i < 9; i++) {
            if (rankCount[i] && rankCount[i+1] && rankCount[i+2] && rankCount[i+3] && rankCount[i+4]) {
                printf("You have a straight!\n");
                score += 800;
                break;
            }
        }
    }

    // Check for pairs
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 2) {
            printf("You have a pair of %ss!\n", rankNames[i]);
            score += 100;
        } else if (rankCount[i] == 3) {
            printf("You have three %ss!\n", rankNames[i]);
            score += 300;
        } else if (rankCount[i] == 4) {
            printf("You have four %ss!\n", rankNames[i]);
            score += 1000;
        }
    }

    // Display hand
    printf("Your hand:\n");
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%s of %ss\n", rankNames[hand[i].rank], suitNames[hand[i].suit]);
    }

    // Display score
    printf("Your score: %d", score);

    return 0;
}