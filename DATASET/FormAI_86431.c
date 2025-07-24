//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_PLAYERS 4
#define MIN_ROUNDS 3
#define MAX_ROUNDS 5

// Struct representing a player
typedef struct {
    int id; // unique identifier for each player
    int score; // player's current score
} Player;

Player players[NUM_PLAYERS]; // global array of players
int currentRound = 1; // global variable tracking current round number
bool gameOver = false; // global flag to indicate if game is over

pthread_mutex_t lock; // mutex to protect shared variables

// Function to perform a single turn for the specified player
void playTurn(Player *player) {
    // Generate a random number between 1 and 10
    int roll = rand() % 10 + 1;
    printf("Player %d rolled a %d\n", player->id, roll);
    
    // If the roll is odd, increment the player's score and print message
    if (roll % 2 == 1) {
        player->score++;
        printf("Player %d gained a point!\n", player->id);
    } else {
        printf("Player %d did not gain a point.\n", player->id);
    }
}

// Function to print out the current scores for all players
void printScores() {
    printf("Current Scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", players[i].id, players[i].score);
    }
}

// Function to check if the game is over (i.e. if any player has reached 10 points)
bool checkGameOver() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].score >= 10) {
            return true;
        }
    }
    return false;
}

// Function to perform one round of the game (each player takes a turn)
void *playRound(void *arg) {
    Player *player = (Player *) arg;

    // Take turns until each player has had a chance to play
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_mutex_lock(&lock); // lock to ensure mutual exclusion
        if (gameOver) {
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
        printf("Round %d, Player %d's turn:\n", currentRound, player->id);
        playTurn(player);
        printScores();
        if (checkGameOver()) {
            printf("Game over!\n"); // print message indicating game end
            gameOver = true; // set global flag to indicate game over
        }
        pthread_mutex_unlock(&lock); // unlock mutex
        usleep(100000); // sleep for 100 milliseconds between turns
        player = (player->id == NUM_PLAYERS) ? players : player + 1; // switch to next player
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // seed random number generator
    pthread_t threads[NUM_PLAYERS]; // array to hold thread ids

    // Initialize players with unique ids and starting score of 0
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i + 1; // player id starts at 1
        players[i].score = 0;
    }

    // Main game loop - play multiple rounds until game over
    while (!gameOver && currentRound <= MAX_ROUNDS) {
        printf("Round %d starting...\n", currentRound);
        // Shuffle array of players to randomize turn order
        for (int i = 0; i < NUM_PLAYERS - 1; i++) {
            int j = rand() % (NUM_PLAYERS - i) + i;
            Player temp = players[i];
            players[i] = players[j];
            players[j] = temp;
        }

        // Spawn a thread for each player to take their turn
        for (int i = 0; i < NUM_PLAYERS; i++) {
            pthread_create(&threads[i], NULL, &playRound, (void *) &players[i]);
        }
        
        // Wait for all threads to finish before starting next round
        for (int i = 0; i < NUM_PLAYERS; i++) {
            pthread_join(threads[i], NULL);
        }

        currentRound++; // increment round counter
        if (currentRound <= MAX_ROUNDS) {
            printf("Round %d complete.\n", currentRound - 1);
            usleep(500000); // sleep for 500 milliseconds between rounds
        }
    }

    // Print final scores
    printf("Final scores:\n");
    printScores();
    
    return 0;
}