//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    int voted;
};

int numCandidates = 0;
struct Candidate candidates[MAX_CANDIDATES];
int numVoters = 0;
struct Voter voters[MAX_VOTERS];

void addCandidate(char name[]) {
    if(numCandidates >= MAX_CANDIDATES) {
        printf("Cannot add more than %d candidates.\n", MAX_CANDIDATES);
        return;
    }
    for(int i = 0; i < numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            printf("%s is already a candidate.\n", name);
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void printCandidates() {
    printf("Available candidates:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void addVoter(char name[]) {
    if(numVoters >= MAX_VOTERS) {
        printf("Cannot add more than %d voters.\n", MAX_VOTERS);
        return;
    }
    for(int i = 0; i < numVoters; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            printf("%s has already voted.\n", name);
            return;
        }
    }
    strcpy(voters[numVoters].name, name);
    voters[numVoters].voted = 0;
    numVoters++;
}

void printVoters() {
    printf("Registered voters:\n");
    for(int i = 0; i < numVoters; i++) {
        printf("%d. %s%s\n", i+1, voters[i].name, voters[i].voted ? " (voted)" : "");
    }
}

void vote(char candidateName[], char voterName[]) {
    for(int i = 0; i < numCandidates; i++) {
        if(strcmp(candidates[i].name, candidateName) == 0) {
            for(int j = 0; j < numVoters; j++) {
                if(strcmp(voters[j].name, voterName) == 0) {
                    if(voters[j].voted) {
                        printf("%s has already voted.\n", voterName);
                        return;
                    }
                    candidates[i].votes++;
                    voters[j].voted = 1;
                    printf("%s voted for %s.\n", voterName, candidateName);
                    return;
                }
            }
            printf("%s is not a registered voter.\n", voterName);
            return;
        }
    }
    printf("%s is not a candidate.\n", candidateName);
}

int main() {
    addCandidate("Alice");
    addCandidate("Bob");
    addCandidate("Charlie");
    printCandidates();
    addVoter("David");
    addVoter("Eric");
    addVoter("Frank");
    printVoters();
    vote("Alice", "David");
    vote("Alice", "Eric");
    printCandidates();
    printVoters();
    vote("Alice", "Frank");
    return 0;
}