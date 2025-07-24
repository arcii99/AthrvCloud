//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_VOTERS 100
#define NUM_CANDIDATES 4

// Candidate struct to hold the candidate's name and number of votes
typedef struct candidate {
    char name[50];
    int votes;
} Candidate;

// Global variables
Candidate candidates[NUM_CANDIDATES] = {{"John Smith", 0}, {"Jane Doe", 0}, {"Bob Johnson", 0}, {"Sara Lee", 0}};
int total_votes = 0;
bool voting_finished = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to simulate a voter casting their vote
void* vote(void* arg) {
    int candidate_index = rand() % NUM_CANDIDATES;
    pthread_mutex_lock(&mutex);
    candidates[candidate_index].votes++;
    total_votes++;
    printf("Voter %ld cast their vote for %s\n", (long)arg, candidates[candidate_index].name);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to simulate the vote counting process
void* count_votes(void* arg) {
    while (!voting_finished) {
        pthread_mutex_lock(&mutex);
        printf("Vote count: \n");
        for (int i = 0; i < NUM_CANDIDATES; i++) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
        printf("Total votes so far: %d\n", total_votes);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Create an array of voter threads
    pthread_t voters[NUM_VOTERS];
    
    // Create a single vote counting thread
    pthread_t vote_counter;
    
    // Create the threads
    for (long i = 0; i < NUM_VOTERS; i++) {
        pthread_create(&voters[i], NULL, vote, (void*)i);
    }
    pthread_create(&vote_counter, NULL, count_votes, NULL);
    
    // Let voting go on for a while
    sleep(10);
    
    // Finish voting
    voting_finished = true;
    
    // Join the threads back together
    for (int i = 0; i < NUM_VOTERS; i++) {
        pthread_join(voters[i], NULL);
    }
    pthread_join(vote_counter, NULL);
    
    // Determine the winner
    Candidate winner = candidates[0];
    for (int i = 1; i < NUM_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    printf("Winner: %s with %d votes!\n", winner.name, winner.votes);
    
    return 0;
}