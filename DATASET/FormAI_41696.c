//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CARDS 16
#define NUM_PAIRS 8
#define NUM_THREADS 2

int cards[NUM_CARDS];
int pairs_found = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* play_game(void* arg);

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = i % NUM_PAIRS + 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, play_game, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* play_game(void* arg) {
    int first_card, first_index;
    int second_card, second_index;

    while (pairs_found < NUM_PAIRS) {
        int card_index1 = rand() % NUM_CARDS;
        int card_index2 = rand() % NUM_CARDS;

        if (cards[card_index1] != 0 && cards[card_index2] != 0 && card_index1 != card_index2) {
            first_card = cards[card_index1];
            first_index = card_index1;
            second_card = cards[card_index2];
            second_index = card_index2;

            printf("Thread %ld flipped over card %d and card %d\n", pthread_self(), first_card, second_card);

            cards[first_index] = 0;
            cards[second_index] = 0;

            if (first_card == second_card) {
                printf("Thread %ld found a pair!\n", pthread_self());

                pthread_mutex_lock(&mutex);
                pairs_found++;
                pthread_mutex_unlock(&mutex);
            }
        }
    }

    printf("Thread %ld finished the game!\n", pthread_self());
    pthread_exit(NULL);
}