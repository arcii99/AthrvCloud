//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_VOTERS 100
#define NUM_OF_CANDIDATES 3

int votes_count[NUM_OF_CANDIDATES] = {0};
pthread_mutex_t vote_mutex;

void *voter(void *args){
   int candidate_id = rand() % NUM_OF_CANDIDATES;
   pthread_mutex_lock(&vote_mutex);
   votes_count[candidate_id]++;
   pthread_mutex_unlock(&vote_mutex);
   return NULL;
}

int main(){
    pthread_t voters[NUM_OF_VOTERS];
    int i;
    pthread_mutex_init(&vote_mutex, NULL);
    for(i=0; i<NUM_OF_VOTERS; i++){
        pthread_create(&voters[i], NULL, voter, NULL);
    }
    for(i=0; i<NUM_OF_VOTERS; i++){
        pthread_join(voters[i], NULL);
    }
    for(i=0; i<NUM_OF_CANDIDATES; i++){
        printf("Candidate %d received %d vote(s).\n", i+1, votes_count[i]);
    }
    pthread_mutex_destroy(&vote_mutex);
    return 0;
}