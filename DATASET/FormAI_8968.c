//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PLAYERS 3
#define MAX_ROUNDS 5

typedef struct {
    int id;
    int score;
} Player;

Player players[NUM_PLAYERS];
pthread_mutex_t lock;

void *play_game(void *player_id) {
    int pid = *(int *)player_id;
    int round;
    for (round = 1; round <= MAX_ROUNDS; round++) {
        int points = rand() % 100;
        pthread_mutex_lock(&lock);
        players[pid].score += points;
        printf("Player %d earned %d points in round %d\n", pid, points, round);
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_PLAYERS];

    srand(time(NULL));

    // Initialize players
    for (i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i;
        players[i].score = 0;
    }

    // Create threads for each player
    for (i = 0; i < NUM_PLAYERS; i++) {
        pthread_create(&threads[i], NULL, play_game, (void *)&players[i].id);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print scores
    printf("\nFinal Scores:\n");
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", i, players[i].score);
    }

    return 0;
}