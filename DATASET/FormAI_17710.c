//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// initialize variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int diceRoll[2] = {0, 0};
int currentPlayer = 1;
int player1Score = 0;
int player2Score = 0;
int isGameOver = 0;

// function declarations
void* getDiceRoll(void* arg);
void* checkScore(void* arg);
void printScore();

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // initialize threads
    pthread_t t1, t2;
    
    // print intro message
    printf("Welcome to C Table Game!\n");
    
    // loop through game until isGameOver is set to true
    while (!isGameOver) {
        // print current player
        printf("Player %d's turn:\n", currentPlayer);
        
        // roll dice
        pthread_create(&t1, NULL, getDiceRoll, NULL);
        pthread_join(t1, NULL);
        
        // check score
        pthread_create(&t2, NULL, checkScore, NULL);
        pthread_join(t2, NULL);
    }
    
    // print final score
    printScore();
    
    return 0;
}

void* getDiceRoll(void* arg) {
    // lock mutex before updating diceRoll
    pthread_mutex_lock(&mutex);
    
    // generate random dice rolls
    diceRoll[0] = rand() % 6 + 1;
    diceRoll[1] = rand() % 6 + 1;
    
    // print dice rolls
    printf("Dice Roll: %d %d\n", diceRoll[0], diceRoll[1]);
    
    // unlock mutex
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void* checkScore(void* arg) {
    // lock mutex before reading diceRoll and updating scores
    pthread_mutex_lock(&mutex);
    
    // calculate score
    int score = diceRoll[0] + diceRoll[1];
    
    // update score based on current player
    if (currentPlayer == 1) {
        player1Score += score;
        printf("Player 1's current score: %d\n", player1Score);
    } else {
        player2Score += score;
        printf("Player 2's current score: %d\n", player2Score);
    }
    
    // check for game over
    if (player1Score >= 100 || player2Score >= 100) {
        printf("Game over!\n");
        isGameOver = 1;
    } else {
        // switch to next player
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }
    
    // unlock mutex
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void printScore() {
    printf("Final Score:\n");
    printf("Player 1: %d\n", player1Score);
    printf("Player 2: %d\n", player2Score);
}