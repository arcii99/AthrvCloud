//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to shuffle the deck
void shuffleDeck(int deck[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int r = rand() % (n - i) + i;
        int temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// function to deal the cards
void dealCards(int deck[], int players, int playerCards[][2], int n) {
    int index = 0;
    for (int i = 0; i < players; ++i) {
        for (int j = 0; j < 2; ++j) {
            playerCards[i][j] = deck[index++];
        }
    }
}

// function to print a card
void printCard(int card) {
    char* suits[] = {"Club", "Diamond", "Heart", "Spade"};
    char* ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("%s of %s", ranks[card % 13], suits[card / 13]);
}

// function to print a player's hand
void printPlayerHand(int playerCards[][2], int player) {
    printf("Player %d's hand: ", player + 1);
    for (int j = 0; j < 2; ++j) {
        printCard(playerCards[player][j]);
        printf(", ");
    }
    printf("\n");
}

// function to check if a hand contains a pair
int hasPair(int playerCards[][2], int player) {
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 2; ++j) {
            if (playerCards[player][i] % 13 == playerCards[player][j] % 13) {
                return 1;
            }
        }
    }
    return 0;
}

// function to determine the winner
int determineWinner(int playerCards[][2], int players) {
    int winner = -1;
    int highestCard = -1;
    for (int i = 0; i < players; ++i) {
        if (hasPair(playerCards, i)) {
            if (playerCards[i][0] % 13 > highestCard || playerCards[i][1] % 13 > highestCard) {
                if (playerCards[i][0] % 13 > playerCards[i][1] % 13) {
                    highestCard = playerCards[i][0] % 13;
                } else {
                    highestCard = playerCards[i][1] % 13;
                }
                winner = i;
            } else if (playerCards[i][0] % 13 == highestCard && playerCards[i][1] % 13 == highestCard) {
                return -1; // tie
            }
        }
    }
    return winner;
}

// main function
int main() {
    int n = 52;
    int deck[n];
    for (int i = 0; i < n; ++i) {
        deck[i] = i;
    }

    shuffleDeck(deck, n);

    int players = 3;
    int playerCards[players][2];
    dealCards(deck, players, playerCards, n);

    for (int i = 0; i < players; ++i) {
        printPlayerHand(playerCards, i);
    }

    int winner = determineWinner(playerCards, players);
    if (winner == -1) {
        printf("There is a tie.\n");
    } else {
        printf("Player %d wins with a pair.\n", winner + 1);
    }

    return 0;
}