//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5

pthread_mutex_t mutex_identifier;
int invasion_probability = 0;

void* calculate_probability(void* id) {
    int thread_id = *((int*)id);
    printf("Thread %d started\n", thread_id);
    srand(time(NULL) + thread_id);
    int random_prob = rand() % 100;
    printf("Thread %d calculated a random probability of %d%%\n", thread_id, random_prob);
    pthread_mutex_lock(&mutex_identifier);
    invasion_probability += random_prob;
    pthread_mutex_unlock(&mutex_identifier);
    printf("Thread %d added its probability to the total invasion probability\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    printf("Alien Invasion Probability Calculator\n");
    printf("Enter the number of attempts: ");
    int num_attempts;
    scanf("%d", &num_attempts);

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex_identifier, NULL);

    for (int i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_probability, &thread_ids[i]);
    }

    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    invasion_probability /= NUM_THREADS;

    printf("After %d attempts, the probability of an Alien Invasion is: %d%%\n", num_attempts, invasion_probability);
    pthread_mutex_destroy(&mutex_identifier);
    pthread_exit(NULL);
}