//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 3

void *tellFortune(void *arg);

char *fortunes[] = {
    "You will receive a great gift soon.",
    "Good luck will be on your side for the next week.",
    "A new love interest will enter your life in the near future.",
    "An unexpected opportunity will arise for you soon.",
    "You will achieve success in your career.",
    "Your financial situation will improve in the coming months.",
    "A long-awaited dream will come true for you this year.",
    "You will make a new friend who will become very important to you."
};

pthread_mutex_t lock;
int fortuneCount = 0;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    pthread_t threads[NUM_THREADS];
    int rc;

    /* Initialize mutex */
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    /* Create threads */
    for (long i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, tellFortune, (void *)i);
        if (rc) {
            printf("Error: return code from pthread_create() is %d.\n", rc);
            return 1;
        }
    }

    /* Wait for threads to finish */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Destroy mutex */
    pthread_mutex_destroy(&lock);

    return 0;
}

void *tellFortune(void *arg) {
    int fortuneIndex;

    while (fortuneCount < 8) {
        /* Generate random fortune index */
        fortuneIndex = rand() % 8;

        /* Lock mutex */
        pthread_mutex_lock(&lock);

        /* Check if fortune has already been told */
        if (fortunes[fortuneIndex] != NULL) {
            /* Print fortune */
            printf("Thread %ld's fortune: %s\n", (long)arg, fortunes[fortuneIndex]);
            fortuneCount++;
            fortunes[fortuneIndex] = NULL;  // Mark fortune as told
        }

        /* Unlock mutex */
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}