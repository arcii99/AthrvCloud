//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_THREADS 4
#define NUM_CANDIDATES 4
#define NUM_VOTERS 20

int votes[NUM_VOTERS][NUM_CANDIDATES] = {0};
int voter_count = 0;
int candidate_count = 0;
int current_voter = 0;
int current_candidate = 0;
int vote_count[NUM_CANDIDATES] = {0};
pthread_mutex_t mutex;

void *cast_vote(void *voter_id) {
    int vid = *(int *)voter_id;
    while (vid != current_voter);
    int vote = rand() % NUM_CANDIDATES;
    votes[vid][vote] = 1;
    vote_count[vote]++;
    printf("Voter %d has casted vote to candidate %d.\n", vid, vote);
    current_voter++;
}

void *count_vote(void *candidate_id) {
    int cid = *(int *)candidate_id;
    while (cid != current_candidate);
    printf("Candidate %d has %d votes.\n", cid, vote_count[cid]);
    current_candidate++;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int voter_ids[NUM_VOTERS];
    int candidate_ids[NUM_CANDIDATES];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_VOTERS; i++) {
        voter_ids[i] = i;
        pthread_create(&threads[i % NUM_THREADS], NULL, cast_vote, &voter_ids[i]);
        if (i % NUM_THREADS == NUM_THREADS - 1) {
            for (int j = 0; j < NUM_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }
  
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        candidate_ids[i] = i;
        pthread_create(&threads[i % NUM_THREADS], NULL, count_vote, &candidate_ids[i]);
        if (i % NUM_THREADS == NUM_THREADS - 1) {
            for (int j = 0; j < NUM_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}