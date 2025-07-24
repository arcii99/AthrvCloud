//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // Number of players in the game
#define TARGET_SCORE 20 // The score to win the game
#define MAX_TURN 3 // Maximum number of turns per round

// Player structure
typedef struct player {
    int id;
    int score;
    int* dice; // Array of dice values
    pthread_cond_t* cond; // Conditional variable to signal turn
    pthread_mutex_t* mutex; // Mutex lock for variable manipulation
} player_t;

// Function to roll the dice
void roll_dice(int* dice) {
    for (int i = 0; i < 5; i++) {
        dice[i] = rand() % 6 + 1;
    }
}

// Function to calculate the score of a roll
int calculate_score(int* dice, int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 1 || dice[i] == 5) {
            score += dice[i] == 1 ? 100 : 50;
        }
    }
    return score;
}

// Function for each player thread
void* play_game(void* arg) {
    player_t* player = (player_t*) arg;
    int turn_count = 0; // Count of player turns
    while (player->score < TARGET_SCORE) {
        pthread_mutex_lock(player->mutex);
        while (turn_count != player->id) { // Wait for player turn
            pthread_cond_wait(player->cond, player->mutex);
        }
        printf("Player %d's turn.\n", player->id);
        roll_dice(player->dice); // Roll dice
        int round_score = calculate_score(player->dice, 5); // Calculate score
        printf("Player %d rolled:\n", player->id);
        for (int i = 0; i < 5; i++) {
            printf("%d ", player->dice[i]);
        }
        printf("\n");
        printf("Player %d scored %d points this round.\n", player->id, round_score);
        player->score += round_score; // Update player score
        turn_count++;
        if (turn_count == NUM_THREADS) { // End of round
            printf("End of round.\n");
            turn_count = 0; // Reset turn count
            for (int i = 0; i < NUM_THREADS; i++) { // Signal next player's turn
                pthread_cond_signal(player[i].cond);
            }
        } else { // Signal next player's turn
            pthread_cond_signal(player[turn_count].cond);
        }
        pthread_mutex_unlock(player->mutex);
    }
    printf("Player %d wins the game!\n", player->id);
    return NULL;
}

int main() {
    // Initialize players
    player_t players[NUM_THREADS];
    pthread_cond_t conds[NUM_THREADS];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    for (int i = 0; i < NUM_THREADS; i++) {
        players[i].id = i;
        players[i].score = 0;
        players[i].dice = malloc(5 * sizeof(int));
        players[i].cond = &conds[i];
        players[i].mutex = &mutex;
        pthread_cond_init(players[i].cond, NULL);
    }

    // Start game
    srand(time(NULL));
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cond_signal(players[i].cond); // Signal first player's turn
        pthread_create(&threads[i], NULL, play_game, (void*) &players[i]);
    }

    // Wait for game to end
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        free(players[i].dice);
        pthread_cond_destroy(players[i].cond);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}