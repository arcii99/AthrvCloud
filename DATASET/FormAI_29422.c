//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define CARDS_PER_HAND 5

char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int deck[52];
int usedCards[52];
int players[NUM_PLAYERS][CARDS_PER_HAND];

void shuffleDeck() {
    int i;
    srand(time(NULL));
    for(i = 0; i < 52; i++) {
        deck[i] = i;
        usedCards[i] = 0;
    }
    for(i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHands() {
    int i, j;
    for(i = 0; i < NUM_PLAYERS; i++) {
        for(j = 0; j < CARDS_PER_HAND; j++) {
            players[i][j] = deck[i*CARDS_PER_HAND + j];
            usedCards[players[i][j]] = 1;
        }
    }
}

void printHand(int hand[]) {
    int i;
    for(i = 0; i < CARDS_PER_HAND; i++) {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;
        printf("%s of %s\n", ranks[rank], suits[suit]);
    }
}

int getRank(int hand[]) {
    int i;
    int rankCount[13] = {0};
    for(i = 0; i < CARDS_PER_HAND; i++) {
        rankCount[hand[i] % 13]++;
    }
    for(i = 0; i < 13; i++) {
        if(rankCount[i] == 4) {
            return 7;
        }
        if(rankCount[i] == 3) {
            for(int j = 0; j < 13; j++) {
                if(rankCount[j] == 2) {
                    return 6;
                }
            }
            return 3;
        }
        if(rankCount[i] == 2) {
            for(int j = i+1; j < 13; j++) {
                if(rankCount[j] == 3) {
                    return 6;
                }
                if(rankCount[j] == 2) {
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    shuffleDeck();
    dealHands();
    int i, maxRank = 0, maxIndex = 0;
    for(i = 0; i < NUM_PLAYERS; i++) {
        printf("Hand %d:\n", i+1);
        printHand(players[i]);
        int rank = getRank(players[i]);
        printf("Rank: %d\n", rank);
        if(rank > maxRank) {
            maxRank = rank;
            maxIndex = i;
        }
        printf("\n");
    }
    printf("The winner is Hand %d with a rank of %d!\n", maxIndex+1, maxRank);
    
    return 0;
}