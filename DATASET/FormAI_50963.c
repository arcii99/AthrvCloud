//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum number of candidates and voters
#define MAX_CANDIDATES 100
#define MAX_VOTERS 1000

// defining the candidate structure
typedef struct Candidate {
    char name[50];
    int id;
    int votes;
} Candidate;

// defining the voter structure
typedef struct Voter {
    char name[50];
    int id;
    int voted;
} Voter;

// defining the list of candidates and the number of candidates
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

// defining the list of voters and the number of voters
Voter voters[MAX_VOTERS];
int num_voters = 0;

// function to add a candidate to the list of candidates
void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    candidates[num_candidates].id = num_candidates + 1;
    candidates[num_candidates].votes = 0;
    strcpy(candidates[num_candidates].name, name);
    num_candidates++;

    printf("Candidate added successfully.\n");
}

// function to add a voter to the list of voters
void add_voter(char *name) {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;
    strcpy(voters[num_voters].name, name);
    num_voters++;

    printf("Voter added successfully.\n");
}

// function to display the list of candidates
void display_candidates() {
    printf("List of Candidates:\n");
    printf("-------------------\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("\n");
}

// function to display the list of voters
void display_voters() {
    printf("List of Voters:\n");
    printf("----------------\n");

    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s (%s)\n", voters[i].id, voters[i].name, voters[i].voted ? "voted" : "not voted");
    }

    printf("\n");
}

// function to vote for a candidate
void vote(int voter_id, int candidate_id) {
    if (voters[voter_id - 1].voted) {
        printf("You have already voted.\n");
        return;
    }

    if (candidate_id < 1 || candidate_id > num_candidates) {
        printf("Invalid candidate id.\n");
        return;
    }

    candidates[candidate_id - 1].votes++;
    voters[voter_id - 1].voted = 1;

    printf("Vote casted successfully.\n");
}

int main() {
    // adding candidates
    add_candidate("John Doe");
    add_candidate("Jane Smith");
    add_candidate("Mike Johnson");

    // adding voters
    add_voter("Alice Jones");
    add_voter("Bob Brown");

    // displaying candidates and voters
    display_candidates();
    display_voters();

    // alice votes for john doe
    vote(1, 1);

    // displaying candidates and voters again
    display_candidates();
    display_voters();

    return 0;
}