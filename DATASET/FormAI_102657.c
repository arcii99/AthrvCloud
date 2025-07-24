//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int player_count = 0;

void* player(void* arg) {
    int* player_id = (int*) arg; // player id assigned to each thread
    int player_score = 0;
    
    pthread_mutex_lock(&mutex);
    player_count++; // Increment the number of players in the game
    printf("Player %d has joined the game\n", *player_id);
    if (player_count < MAX_PLAYERS) {
        pthread_cond_wait(&cond, &mutex);
    } else {
        pthread_cond_broadcast(&cond); // signal all the waiting players to start
    }
    pthread_mutex_unlock(&mutex);
    
    // Game logic
    for (int i = 0; i < 5; i++) {
        int points = rand() % 100 + 1; // Generate a random number between 1 and 100
        player_score += points;
        printf("Player %d scored %d points in round %d\n", *player_id, points, i+1);
    }
    
    printf("Player %d's final score is %d\n", *player_id, player_score);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];
    
    srand(time(NULL)); // Set seed for random number generator
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_ids[i] = i+1; // Player id starts from 1
        pthread_create(&threads[i], NULL, player, &player_ids[i]); // Create a new thread for each player
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL); // Wait for all the players to finish playing
    }
    
    printf("All players have finished playing\n");
    return 0;
}