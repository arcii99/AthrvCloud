//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_PLAYERS 4

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int deck[52]; // each card is represented by an integer value from 0 to 51
int players[NUM_PLAYERS][2]; // player hands
int playerCount[NUM_PLAYERS]; // number of cards in each hand
int playerScores[NUM_PLAYERS]; // each player's current score
int currentPlayer = 0;

void initializeDeck() {
    for(int i = 0; i < 52; i++) {
        deck[i] = i;
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for(int i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int getCardValue(int card) {
    int value = card % 13 + 1;
    if(value > 10) {
        value = 10;
    }
    return value;
}

void dealCard(int player) {
    int card = deck[0];
    deck[0] = deck[51];
    deck[51] = card;
    playerCount[player] += 1;
    players[player][playerCount[player]-1] = card;
    playerScores[player] += getCardValue(card);
}

void printPlayerHand(int player) {
    for(int i = 0; i < playerCount[player]; i++) {
        int card = players[player][i];
        int rank = card % 13 + 1;
        int suit = card / 13;
        switch(rank) {
            case 1: printf("Ace of "); break;
            case 11: printf("Jack of "); break;
            case 12: printf("Queen of "); break;
            case 13: printf("King of "); break;
            default: printf("%d of ", rank);
        }
        switch(suit) {
            case 0: printf("Spades\n"); break;
            case 1: printf("Hearts\n"); break;
            case 2: printf("Clubs\n"); break;
            case 3: printf("Diamonds\n"); break;
        }
    }
    printf("Total: %d\n", playerScores[player]);
}

void* playerThread(void* arg) {
    int playerNumber = *(int*)arg;
    while(1) {
        pthread_mutex_lock(&mutex);
        if(currentPlayer != playerNumber) {
            pthread_mutex_unlock(&mutex);
            usleep(100000);
            continue;
        }
        if(playerScores[playerNumber] >= 21 || playerCount[playerNumber] >= 5) {
            printf("Player %d stands\n", playerNumber);
        }
        else {
            printf("Player %d hits\n", playerNumber);
            dealCard(playerNumber);
            printPlayerHand(playerNumber);
            if(playerScores[playerNumber] >= 21) {
                printf("Player %d busts\n", playerNumber);
            }
        }
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
}

int main() {
    initializeDeck();
    shuffleDeck();
    for(int i = 0; i < NUM_PLAYERS; i++) {
        players[i][0] = -1;
        players[i][1] = -1;
        playerCount[i] = 0;
        playerScores[i] = 0;
    }
    pthread_t threads[NUM_PLAYERS];
    int playerNumbers[NUM_PLAYERS];
    for(int i = 0; i < NUM_PLAYERS; i++) {
        playerNumbers[i] = i;
        pthread_create(&threads[i], NULL, playerThread, &playerNumbers[i]);
    }
    while(1) {
        usleep(100000);
    }
    return 0;
}