//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_CARDS 10
#define NUM_THREADS 2

int cards[NUM_CARDS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int num_pairs = 0;

void init_cards() {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = rand() % 5;
    }
}

void print_cards() {
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");
}

void *player(void *args) {
    int id = *(int *) args;
    int flipped1 = -1, flipped2 = -1;

    while (num_pairs < NUM_CARDS / 2) {
        int index = rand() % NUM_CARDS;

        pthread_mutex_lock(&mutex);

        if (cards[index] != -1) {
            if (flipped1 == -1) {
                flipped1 = index;
            } else if (flipped2 == -1) {
                flipped2 = index;
            }

            if (flipped1 != -1 && flipped2 != -1) {
                if (cards[flipped1] == cards[flipped2]) {
                    printf("Player %d found a pair!\n", id);
                    cards[flipped1] = -1;
                    cards[flipped2] = -1;
                    num_pairs++;
                } else {
                    printf("Player %d did not find a pair.\n", id);
                }
                flipped1 = -1;
                flipped2 = -1;
            }
        }

        pthread_mutex_unlock(&mutex);

        usleep(10000);
    }

    printf("Player %d has finished.\n", id);

    pthread_exit(NULL);
}

int main() {
    init_cards();
    print_cards();

    int ids[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, player, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All players have finished!\n");

    return 0;
}