//FormAI DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

void initializeDeck(int deck[]);
void shuffleDeck(int deck[]);
void printDeck(int deck[]);
void printHand(int hand[]);
void dealCards(int deck[], int hand[]);
int evaluateHand(int hand[]);
void swap(int *a, int *b);

int main() {
    int deck[DECK_SIZE];
    int hand[HAND_SIZE];

    srand(time(NULL)); // set random seed for shuffling

    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, hand);

    printf("Your hand is:\n");
    printHand(hand);

    int handRank = evaluateHand(hand);
    printf("\nYour hand ranks as a ");

    switch(handRank) {
        case 1:
            printf("high card.");
            break;
        case 2:
            printf("one pair.");
            break;
        case 3:
            printf("two pair.");
            break;
        case 4:
            printf("three of a kind.");
            break;
        case 5:
            printf("straight.");
            break;
        case 6:
            printf("flush.");
            break;
        case 7:
            printf("full house.");
            break;
        case 8:
            printf("four of a kind.");
            break;
        case 9:
            printf("straight flush.");
            break;
        case 10:
            printf("royal flush!");
            break;
        default:
            printf("nothing!");
            break;
    }

    return 0;
}

void initializeDeck(int deck[]) {
    for(int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
}

void shuffleDeck(int deck[]) {
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        swap(&deck[i], &deck[j]);
    }
}

void printDeck(int deck[]) {
    for(int i = 0; i < DECK_SIZE; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

void printHand(int hand[]) {
    for(int i = 0; i < HAND_SIZE; i++) {
        int suit = hand[i] / 13;
        int rank = hand[i] % 13;

        switch(rank) {
            case 0:
                printf("Ace ");
                break;
            case 10:
                printf("Jack ");
                break;
            case 11:
                printf("Queen ");
                break;
            case 12:
                printf("King ");
                break;
            default:
                printf("%d ", rank + 1);
        }

        switch(suit) {
            case 0:
                printf("of Spades\n");
                break;
            case 1:
                printf("of Hearts\n");
                break;
            case 2:
                printf("of Clubs\n");
                break;
            case 3:
                printf("of Diamonds\n");
                break;
            default:
                printf("Error: unknown suit\n");
        }
    }
}

void dealCards(int deck[], int hand[]) {
    for(int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

int evaluateHand(int hand[]) {
    int ranks[13] = {0};
    int suits[4] = {0};
    int straight = 0;
    int flush = 0;
    int pairs = 0;
    int triples = 0;
    int quadruples = 0;

    for(int i = 0; i < HAND_SIZE; i++) {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;

        ranks[rank]++;
        suits[suit]++;

        if(ranks[rank] == 2) {
            pairs++;
        }
        if(ranks[rank] == 3) {
            triples++;
        }
        if(ranks[rank] == 4) {
            quadruples++;
        }
    }

    // Check for flush
    for(int i = 0; i < 4; i++) {
        if(suits[i] == HAND_SIZE) {
            flush = 1;
            break;
        }
    }

    // Check for straight
    for(int i = 0; i < 9; i++) {
        if(ranks[i] && ranks[i+1] && ranks[i+2] && ranks[i+3] && ranks[i+4]) {
            straight = 1;
            break;
        }
    }
    // Check for Ace, 10, Jack, Queen, King sequence (a.k.a. Royal Flush)
    if(ranks[0] && ranks[9] && ranks[10] && ranks[11] && ranks[12]) {
        straight = 1;
    }

    // Evaluate hand
    if(straight && flush && ranks[0] && ranks[9] && ranks[10] && ranks[11] && ranks[12]) {
        return 10; // Royal Flush
    }
    if(straight && flush) {
        return 9; // Straight Flush
    }
    if(quadruples) {
        return 8; // Four of a Kind
    }
    if(triples && pairs) {
        return 7; // Full House
    }
    if(flush) {
        return 6; // Flush
    }
    if(straight) {
        return 5; // Straight
    }
    if(triples) {
        return 4; // Three of a Kind
    }
    if(pairs == 2) {
        return 3; // Two Pair
    }
    if(pairs == 1) {
        return 2; // One Pair
    }

    // If no strong hand, return highest card rank
    for(int i = 12; i >= 0; i--) {
        if(ranks[i]) {
            return 1; // Highest card
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}