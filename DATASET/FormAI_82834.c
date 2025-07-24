//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 1000

// Define Candidate struct
struct Candidate {
    int id;
    char name[50];
    int votes;
};

// Define Voter struct
struct Voter {
    int id;
    char name[50];
    int voted_id;
    int has_voted;
};

// Define global variables
struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate
void add_candidate(int id, char name[50]) {
    struct Candidate candidate;
    candidate.id = id;
    strcpy(candidate.name, name);
    candidate.votes = 0;
    candidates[num_candidates++] = candidate;
}

// Function to add a voter
void add_voter(int id, char name[50]) {
    struct Voter voter;
    voter.id = id;
    strcpy(voter.name, name);
    voter.voted_id = -1;
    voter.has_voted = 0;
    voters[num_voters++] = voter;
}

// Function to display the candidates
void display_candidates() {
    printf("ID\tName\tVotes\n");
    printf("------------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote
void cast_vote(int voter_id, int candidate_id) {
    // Find the voter
    struct Voter* voter = NULL;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter = &voters[i];
            break;
        }
    }

    // Find the candidate
    struct Candidate* candidate = NULL;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidate = &candidates[i];
            break;
        }
    }

    // Cast the vote
    if (voter && candidate) {
        if (voter->has_voted) {
            printf("Error: Voter already cast a vote.\n");
        } else {
            voter->voted_id = candidate_id;
            voter->has_voted = 1;
            candidate->votes++;
            printf("Vote cast by %s for %s.\n", voter->name, candidate->name);
        }
    } else {
        printf("Error: Invalid voter or candidate ID.\n");
    }
}

int main() {
    // Add candidates
    add_candidate(1, "John Smith");
    add_candidate(2, "Sarah Johnson");
    add_candidate(3, "Mike Brown");

    // Add voters
    add_voter(1001, "Alice Roberts");
    add_voter(1002, "Bob Johnson");
    add_voter(1003, "Charlie Brown");
    add_voter(1004, "David Wilson");

    // Cast some votes
    cast_vote(1001, 1);
    cast_vote(1002, 2);
    cast_vote(1003, 3);
    cast_vote(1004, 1);

    // Display the candidates and their votes
    display_candidates();

    return 0;
}