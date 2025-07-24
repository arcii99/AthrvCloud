//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PLAYERS 5
#define THREAD_COUNT 2

int scores[NUM_PLAYERS] = {0};
pthread_mutex_t score_lock;

void *player_thread(void *player_id){
    int id = (int) player_id;
    printf("Player %d has joined the game!\n", id);

    while(1){
        pthread_mutex_lock(&score_lock);
        int target = rand() % NUM_PLAYERS;
        while(target == id) target = rand() % NUM_PLAYERS;

        int points = rand() % 10 + 1;
        printf("Player %d has hit Player %d for %d points!\n", id, target, points);

        scores[target] -= points;
        if(scores[target] <= 0){
            printf("Player %d has eliminated Player %d!\n", id, target);
            scores[id]++;
            scores[target] = 10;
        }
        pthread_mutex_unlock(&score_lock);
        sleep(1);
    }
}

int main(){
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_init(&score_lock, NULL);

    for(int i=0; i<NUM_PLAYERS; i++) scores[i] = 10;

    for(int i=0; i<THREAD_COUNT; i++){
        pthread_create(&threads[i], NULL, player_thread, (void*) i);
    }

    while(1){
        pthread_mutex_lock(&score_lock);
        int alive = 0, winner;
        for(int i=0; i<NUM_PLAYERS; i++){
            if(scores[i] > 0){
                alive++;
                winner = i;
            }
        }
        if(alive == 1){
            printf("\n\nGame over! Player %d wins!\n\n", winner);
            pthread_mutex_unlock(&score_lock);
            break;
        }
        pthread_mutex_unlock(&score_lock);
        sleep(3);
    }

    for(int i=0; i<THREAD_COUNT; i++){
        pthread_cancel(threads[i]);
    }

    pthread_mutex_destroy(&score_lock);
    return 0;
}