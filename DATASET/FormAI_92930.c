//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VOTERS 1000 // maximum number of voters
#define MAX_CANDIDATES 30 // maximum number of candidates
#define MAX_NAME_LENGTH 50 // maximum length of a candidate's name

// struct for a candidate
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// struct for a voter
typedef struct {
    int id;
    bool hasVoted;
} Voter;

// array of candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int numCandidates = 0; // number of candidates
int numVoters = 0; // number of voters

// function to add a candidate
void addCandidate(char* name) {
    if (numCandidates == MAX_CANDIDATES) {
        printf("Max number of candidates reached!\n");
        return;
    }
    Candidate candidate;
    candidate.id = numCandidates + 1;
    strcpy(candidate.name, name);
    candidate.votes = 0;
    candidates[numCandidates] = candidate;
    numCandidates++;
}

// function to print all candidates
void printCandidates() {
    printf("ID\tName\t\tVotes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%s\t\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// function to vote for a candidate
void vote(int voterId, int candidateId) {
    if (voters[voterId].hasVoted) {
        printf("Voter has already voted!\n");
        return;
    }
    if (candidateId < 1 || candidateId > numCandidates) {
        printf("Invalid candidate ID!\n");
        return;
    }
    candidates[candidateId - 1].votes++;
    voters[voterId].hasVoted = true;
    printf("Vote cast for %s!\n", candidates[candidateId - 1].name);
}

// function to print all voters
void printVoters() {
    printf("ID\tVoted?\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d\t%s\n", voters[i].id, voters[i].hasVoted ? "Yes" : "No");
    }
}

int main() {
    // add candidates
    addCandidate("John");
    addCandidate("Jane");
    addCandidate("Jim");
    
    // add voters
    for (int i = 0; i < 10; i++) {
        Voter voter;
        voter.id = numVoters + 1;
        voter.hasVoted = false;
        voters[numVoters] = voter;
        numVoters++;
    }
    
    // print initial state
    printf("Initial state:\n");
    printCandidates();
    printVoters();
    
    // conduct election
    vote(0, 1);
    vote(1, 2);
    vote(2, 1);
    vote(3, 1);
    vote(4, 3);
    vote(5, 2);
    vote(6, 1);
    vote(7, 2);
    vote(8, 3);
    vote(9, 1);
    
    // print final state
    printf("\nFinal state:\n");
    printCandidates();
    printVoters();
    
    return 0;
}