//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100
#define NUM_THREADS 10

int votes[NUM_CANDIDATES] = {0};
int voter_ids[NUM_VOTERS] = {0};
pthread_mutex_t lock;

void *vote(void *arg) {
    int voter_id = *(int*) arg;
    int candidate_choice = rand() % NUM_CANDIDATES;
    pthread_mutex_lock(&lock);
    printf("Voter %d voted for candidate %d\n", voter_id, candidate_choice);
    votes[candidate_choice]++;
    pthread_mutex_unlock(&lock);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    pthread_mutex_init(&lock, NULL);

    // Generate voter IDs
    for (i = 0; i < NUM_VOTERS; i++) {
        voter_ids[i] = i + 1;
    }

    // Spawn threads for each voter
    for (i = 0; i < NUM_VOTERS; i++) {
        int *voter_id = malloc(sizeof(int));
        *voter_id = voter_ids[i];
        pthread_create(&threads[i % NUM_THREADS], NULL, vote, voter_id);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print voting results
    printf("\n=====================\n");
    printf("   Voting Results\n");
    printf("=====================\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i, votes[i]);
    }

    return 0;
}