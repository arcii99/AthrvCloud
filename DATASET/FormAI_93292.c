//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure for candidate
typedef struct Candidate {
    char name[30];
    int votes;
} Candidate;

// function to display candidates and their votes
void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("Candidate\tVotes\n");
    printf("-----------------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // set up random number generator
    srand(time(NULL));

    // create array of candidates
    const int numCandidates = 5;
    Candidate candidates[numCandidates];
    strcpy(candidates[0].name, "John Smith");
    strcpy(candidates[1].name, "Sarah Johnson");
    strcpy(candidates[2].name, "Tom Brown");
    strcpy(candidates[3].name, "Emily Davis");
    strcpy(candidates[4].name, "Chris Lee");
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = rand() % 100;
    }

    // display candidates and their votes
    displayCandidates(candidates, numCandidates);

    // simulate voting process
    int numVoters = 200;
    for (int i = 0; i < numVoters; i++) {
        int candidateIndex = rand() % numCandidates;
        candidates[candidateIndex].votes++;
    }

    // display updated candidates and their votes
    printf("\nAfter voting:\n");
    displayCandidates(candidates, numCandidates);

    return 0;
}