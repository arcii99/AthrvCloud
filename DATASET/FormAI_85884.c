//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int is_game_over = 0; // global flag to indicate whether the game is over

pthread_mutex_t lock; // mutex lock for thread synchronization

void *player1(void *arg);
void *player2(void *arg);

int main() {
    srand(time(NULL)); // seed the random number generator
    
    pthread_t tid1, tid2;
    pthread_mutex_init(&lock, NULL); // initialize mutex lock

    int p1_score = 0, p2_score = 0; // initialize player scores to 0

    printf("Welcome to the C Table Game!\n");
    printf("Player 1: press '1' to score\n");
    printf("Player 2: press '2' to score\n");

    pthread_create(&tid1, NULL, player1, &p1_score); // create player 1 thread
    pthread_create(&tid2, NULL, player2, &p2_score); // create player 2 thread

    while (!is_game_over) {
        pthread_mutex_lock(&lock); // acquire lock
        printf("Player 1 score: %d\n", p1_score);
        printf("Player 2 score: %d\n", p2_score);
        pthread_mutex_unlock(&lock); // release lock
        sleep(1); // wait for 1 second
    }

    if (p1_score > p2_score) {
        printf("Player 1 wins!\n");
    } else if (p2_score > p1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    pthread_join(tid1, NULL); // wait for player 1 thread to complete
    pthread_join(tid2, NULL); // wait for player 2 thread to complete

    pthread_mutex_destroy(&lock); // destroy mutex lock
    
    return 0;
}

// player 1 thread function
void *player1(void *arg) {
    int *p_score = (int *) arg;
    while (!is_game_over) {
        char ch = getchar(); // read player input
        if (ch == '1') {
            pthread_mutex_lock(&lock); // acquire lock
            (*p_score)++; // increase player score
            pthread_mutex_unlock(&lock); // release lock
        }
    }
    pthread_exit(NULL); // exit thread
}

// player 2 thread function
void *player2(void *arg) {
    int *p_score = (int *) arg;
    while (!is_game_over) {
        int rand_num = rand() % 10 + 1; // generate random number between 1 and 10
        sleep(rand_num); // wait for random amount of time
        pthread_mutex_lock(&lock); // acquire lock
        (*p_score)++; // increase player score
        pthread_mutex_unlock(&lock); // release lock
    }
    pthread_exit(NULL); // exit thread
}