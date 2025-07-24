//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    int numCandidates, numVoters, i, j, vote;
    printf("Welcome to the Electronic Voting System.\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);
    struct Candidate candidates[numCandidates];
    for(i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);
    for(i = 0; i < numVoters; i++) {
        printf("Voter %d, please enter your vote:\n", i + 1);
        for(j = 0; j < numCandidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }
        scanf("%d", &vote);
        candidates[vote - 1].votes++;
        printf("Vote recorded.\n");
    }
    printf("The results are in!\n");
    for(i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    return 0;
}