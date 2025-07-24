//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_VOTERS 5000

// Voter structure
typedef struct {
    int id;
    bool voted;
    int vote;
} voter_t;

// Global variables
int candidate1 = 0, candidate2 = 0;
voter_t voters[MAX_VOTERS];
int num_voters = 0;
int num_voted = 0;
pthread_mutex_t lock;

// Function to print election results
void print_results() {
    printf("Total votes: %d\n", num_voted);
    printf("Candidate 1: %d votes\n", candidate1);
    printf("Candidate 2: %d votes\n", candidate2);
    if (candidate1 > candidate2) {
        printf("Candidate 1 wins!\n");
    } else if (candidate2 > candidate1) {
        printf("Candidate 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

// Function to handle a voter's vote
void cast_vote(int id, int vote) {
    pthread_mutex_lock(&lock);
    if (vote == 1) {
        candidate1++;
    } else if (vote == 2) {
        candidate2++;
    }
    voters[id].voted = true;
    voters[id].vote = vote;
    num_voted++;
    pthread_mutex_unlock(&lock);
}

// Function for the voter thread
void* voter_thread(void* arg) {
    int id = *(int*)arg;
    int vote = rand() % 2 + 1; // Random vote for either candidate 1 or 2
    printf("Voter %d casts vote for candidate %d\n", id, vote);
    cast_vote(id, vote);
    return NULL;
}

// Function for the election monitor thread
void* monitor_thread(void* arg) {
    sleep(30); // Wait 30 seconds for all voters to cast their votes
    print_results(); // Print the resulting tally of votes
    return NULL;
}

int main() {
    int i;
    pthread_t voter_threads[MAX_VOTERS];
    pthread_t monitor;
    pthread_mutex_init(&lock, NULL);
    
    // Initialize voters
    for (i = 0; i < MAX_VOTERS; i++) {
        voters[i].id = i;
        voters[i].voted = false;
        voters[i].vote = 0;
    }
    
    // Create voter threads
    for (i = 0; i < MAX_VOTERS; i++) {
        pthread_create(&voter_threads[i], NULL, voter_thread, (void*)&voters[i].id);
        num_voters++;
    }
    
    // Create election monitor thread
    pthread_create(&monitor, NULL, monitor_thread, NULL);
    
    // Join voter threads
    for (i = 0; i < MAX_VOTERS; i++) {
        pthread_join(voter_threads[i], NULL);
    }
    
    // Join election monitor thread
    pthread_join(monitor, NULL);
    
    pthread_mutex_destroy(&lock);
    return 0;
}