//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
// C Electronic Voting System example program by Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining maximum number of candidates and voters
#define MAX_CANDIDATES 100
#define MAX_VOTERS 10000

// Structure for candidate
typedef struct {
    char name[100];
    int votes;
} Candidate;

// Array of candidates and number of candidates
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

// Structure for voter
typedef struct {
    char name[100];
    int vote;
} Voter;

// Array of voters and number of voters
Voter voters[MAX_VOTERS];
int num_voters = 0;

// Function to add candidate
void addCandidate(char name[]) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

// Function to add voter and their vote
void addVoter(char name[], int vote) {
    strcpy(voters[num_voters].name, name);
    voters[num_voters].vote = vote;
    num_voters++;
}

// Function to count votes and declare winner
void countVotes() {
    int max_votes = 0;
    int winner = 0;
    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            if (voters[j].vote == i) {
                candidates[i].votes++;
            }
        }
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }
    printf("\nWinner: %s\n", candidates[winner].name);
    printf("Votes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("Welcome to the C Electronic Voting System\n");

    // Adding candidates
    addCandidate("Candidate 1");
    addCandidate("Candidate 2");
    addCandidate("Candidate 3");

    // Adding voters and their votes
    addVoter("Voter 1", 0);
    addVoter("Voter 2", 1);
    addVoter("Voter 3", 2);
    addVoter("Voter 4", 0);
    addVoter("Voter 5", 1);

    // Counting votes and declaring winner
    countVotes();

    return 0;
}