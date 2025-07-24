//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_BUNNIES 5

pthread_mutex_t bunny_mutex;
int num_carrots = 10;

void *bunny_thread(void *arg) {
    int id = *(int *) arg;
    printf("Bunny %d has been born!\n", id);

    while (num_carrots > 0) {
        pthread_mutex_lock(&bunny_mutex);
        if (num_carrots > 0) {
            num_carrots--;
            printf("Bunny %d ate a carrot! %d carrots left.\n", id, num_carrots);
        }
        pthread_mutex_unlock(&bunny_mutex);

        usleep(500000); // Wait for half a second
    }

    printf("Bunny %d has eaten all the carrots and went to sleep!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t bunnies[NUM_BUNNIES];
    int bunny_ids[NUM_BUNNIES];
    int i;

    pthread_mutex_init(&bunny_mutex, NULL);

    printf("Welcome to Bunny World! We have %d bunnies and %d carrots!\n", NUM_BUNNIES, num_carrots);

    for (i = 0; i < NUM_BUNNIES; i++) {
        bunny_ids[i] = i + 1;
        pthread_create(&bunnies[i], NULL, bunny_thread, &bunny_ids[i]);
    }

    for (i = 0; i < NUM_BUNNIES; i++) {
        pthread_join(bunnies[i], NULL);
    }

    printf("All the bunnies have eaten all the carrots and went to sleep. Goodnight Bunny World!\n");

    pthread_mutex_destroy(&bunny_mutex);
    return 0;
}