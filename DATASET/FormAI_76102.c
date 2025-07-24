//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PLAYERS 4
#define MAX_SCORE 100
#define SCORE_INCREMENT 10

int scores[NUM_PLAYERS] = {0};
pthread_mutex_t lock;

void *player(void *arg) {
    int player_id = *((int *) arg);
    while (1) {
        int score_increment = rand() % SCORE_INCREMENT + 1;
        pthread_mutex_lock(&lock);
        if (scores[player_id] + score_increment < MAX_SCORE) {
            scores[player_id] += score_increment;
        } else {
            scores[player_id] = MAX_SCORE;
            printf("Player %d wins!\n", player_id);
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

int main() {
    pthread_t threads[NUM_PLAYERS];
    pthread_mutex_init(&lock, NULL);
    int player_ids[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        player_ids[i] = i;
        pthread_create(&threads[i], NULL, player, &player_ids[i]);
    }

    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    return 0;
}