//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PLAYERS 4 // number of players in game
#define NUM_RANKS 13 // number of card ranks
#define NUM_SUITS 4 // number of card suits

// global variables
int deck[NUM_RANKS][NUM_SUITS];
int playerHands[NUM_PLAYERS][5]; // each player's hand
int playerScores[NUM_PLAYERS]; // each player's score
int currentPlayerIndex = 0; // index of current player
int numCardsInDeck = NUM_RANKS * NUM_SUITS;

// function for initializing deck
void initDeck() {
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[i][j] = 1;
        }
    }
}

// function for dealing cards to players
void dealCards() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            // randomly select a card from deck and add to player's hand
            int cardAdded = 0;
            while (!cardAdded) {
                int rank = rand() % NUM_RANKS;
                int suit = rand() % NUM_SUITS;
                if (deck[rank][suit]) {
                    playerHands[j][i] = rank + 1; // add 1 to rank to adjust for 0-based index
                    deck[rank][suit] = 0; // remove card from deck
                    cardAdded = 1;
                }
            }
        }
    }
}

// function for displaying a player's hand
void displayHand(int playerIndex) {
    printf("Player %d's hand:\n", playerIndex + 1);
    for (int i = 0; i < 5; i++) {
        printf("%d ", playerHands[playerIndex][i]);
    }
    printf("\n");
}

// function for determining if a hand contains a pair
int checkForPair(int* hand) {
    int pairs = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand[i] == hand[j]) {
                pairs++;
            }
        }
    }
    return pairs;
}

// function for determining a hand's score
int calculateScore(int* hand) {
    int score = 0;
    int pairs = checkForPair(hand);
    if (pairs == 1) {
        score = 10;
    }
    else if (pairs == 2) {
        score = 20;
    }
    else if (pairs == 3) {
        score = 30;
    }
    else if (pairs == 4) {
        score = 40;
    }
    else if (pairs == 6) { // three pairs, also known as a full house
        score = 50;
    }
    else { // no pairs
        score = hand[4]; // score is based on highest card in hand
    }
    return score;
}

// function for playing a round
void playRound() {
    printf("Round starting...\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        displayHand(i);
        playerScores[i] = calculateScore(playerHands[i]);
        printf("Player %d's score: %d\n", i + 1, playerScores[i]);
    }
    printf("Round completed.\n");
}

// function for finding the winner of the game
int findWinner() {
    int maxScore = 0;
    int winnerIndex = -1;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (playerScores[i] > maxScore) {
            maxScore = playerScores[i];
            winnerIndex = i;
        }
    }
    return winnerIndex;
}

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // initialize deck
    initDeck();
    
    // deal cards
    dealCards();
    
    // play rounds until deck is empty
    while (numCardsInDeck > 0) {
        playRound();
        currentPlayerIndex = (currentPlayerIndex + 1) % NUM_PLAYERS;
        numCardsInDeck -= NUM_PLAYERS;
    }
    
    // find winner
    int winnerIndex = findWinner();
    printf("Player %d wins!\n", winnerIndex + 1);
    
    return 0;
}