//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VOTERS 10000
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

int voters[MAX_VOTERS];
int num_voters = 0;

// Add a candidate to the candidate list
void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Too many candidates.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

// Add a voter to the voter list
void add_voter(int voter_id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Too many voters.\n");
        return;
    }
    voters[num_voters] = voter_id;
    num_voters++;
}

// Vote for a candidate
void vote(int candidate_index, int voter_id) {
    // Check if voter has already voted
    for (int i = 0; i < num_voters; i++) {
        if (voters[i] == voter_id) {
            printf("Error: You have already voted.\n");
            return;
        }
    }
    // Check if candidate_index is valid
    if (candidate_index < 0 || candidate_index >= num_candidates) {
        printf("Error: Invalid candidate index.\n");
        return;
    }
    // Vote for candidate
    candidates[candidate_index].votes++;
    add_voter(voter_id);
    printf("Vote counted.\n");
}

// Get index of candidate with highest number of votes
int get_winner_index() {
    int winner_index = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner_index].votes) {
            winner_index = i;
        }
    }
    return winner_index;
}

// Print results of election
void print_election_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    int winner_index = get_winner_index();
    printf("Winner: %s\n", candidates[winner_index].name);
}

int main() {
    // Initialize candidate list
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");
    
    // Simulate voting
    vote(0, 1); // Alice gets a vote from voter 1
    vote(1, 2); // Bob gets a vote from voter 2
    vote(1, 3); // Bob gets a vote from voter 3
    vote(2, 4); // Charlie gets a vote from voter 4
    vote(0, 5); // Alice gets a vote from voter 5
    
    // Print results
    print_election_results();
    
    return 0;
}