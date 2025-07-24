//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_VOTERS 100
#define NUM_CANDIDATES 4

int candidate_votes[NUM_CANDIDATES] = {0};
int voter_count = 0;
pthread_mutex_t lock;
pthread_cond_t vote_cond;

void *cast_vote(void *arg) {
    int *voter_id = (int *) arg;
    int candidate_choice = rand() % NUM_CANDIDATES;
    pthread_mutex_lock(&lock);
    candidate_votes[candidate_choice]++;
    voter_count++;
    printf("Voter %d has cast their vote for candidate %d.\n", *voter_id, candidate_choice);
    if (voter_count == NUM_VOTERS) {
        printf("All voters have cast their votes. Sending results.\n");
        pthread_cond_signal(&vote_cond);
    }
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    int voter_ids[NUM_VOTERS];
    pthread_t threads[NUM_THREADS];

    // Initialize mutex and condition variable
    pthread_mutex_init(&lock, NULL); 
    pthread_cond_init(&vote_cond, NULL); 

    // Create threads
    for (int i = 0; i < NUM_VOTERS; i++) {
        voter_ids[i] = i + 1;
        pthread_create(&threads[i % NUM_THREADS], NULL, cast_vote, (void *) &voter_ids[i]);
        if ((i+1) % NUM_THREADS == 0) {
            for (int j = 0; j < NUM_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }

    // Wait for all voters to finish casting their votes
    pthread_mutex_lock(&lock);
    while (voter_count != NUM_VOTERS) {
        pthread_cond_wait(&vote_cond, &lock);
    }

    // Print results
    printf("Election Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i, candidate_votes[i]);
    }

    // Cleanup and exit
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&vote_cond);
    pthread_exit(NULL);
}