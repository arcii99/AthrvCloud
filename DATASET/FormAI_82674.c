//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

int candidates[MAX_CANDIDATES] = {0};
pthread_mutex_t lock[MAX_CANDIDATES];
pthread_mutex_t lock_voters;

void cast_vote(void *arg) {
    int *cand_id = (int *)arg;
    pthread_mutex_lock(&lock[*cand_id]);
    candidates[*cand_id]++;
    pthread_mutex_unlock(&lock[*cand_id]);
}

void *cast_votes(void *arg) {
    int i, num_votes_per_thread = MAX_VOTERS/10;
    for(i=0; i<num_votes_per_thread; i++) {
        int candidate_id = rand() % MAX_CANDIDATES;
        cast_vote(&candidate_id);
    }
    pthread_exit(NULL);
}

void display_results() {
    int i, max_votes = 0, winner_id;
    for(i=0; i<MAX_CANDIDATES; i++) {
        pthread_mutex_lock(&lock[i]);
        if(candidates[i] > max_votes) {
            max_votes = candidates[i];
            winner_id = i;
        }
        pthread_mutex_unlock(&lock[i]);
    }
    printf("\n\nThe winner is Candidate %d with %d votes!\n\n", winner_id, max_votes);
}

int main(void) {
    pthread_t threads[10];
    int i, voters = 0, id[MAX_CANDIDATES];
    
    srand(time(NULL));
    
    for(i=0; i<MAX_CANDIDATES; i++) {
        pthread_mutex_init(&lock[i], NULL);
        id[i] = i;
    }
    
    pthread_mutex_init(&lock_voters, NULL);
    
    for(i=0; i<10; i++) {
        pthread_create(&threads[i], NULL, cast_votes, NULL);
        voters += MAX_VOTERS/10;
    }
    
    for(i=0; i<10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    display_results();
    
    for(i=0; i<MAX_CANDIDATES; i++) {
        pthread_mutex_destroy(&lock[i]);
    }
    
    pthread_mutex_destroy(&lock_voters);
    
    return 0;
}