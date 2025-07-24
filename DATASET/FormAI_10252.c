//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates;
    printf("How many candidates are there? ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_votes;
    printf("How many votes are there? ");
    scanf("%d", &num_votes);

    for (int i = 0; i < num_votes; i++) {
        printf("Enter vote %d's candidate number: ", i+1);
        int candidate_num;
        scanf("%d", &candidate_num);
        candidates[candidate_num-1].votes++;
    }

    printf("Vote results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int winner = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    printf("The winner is %s!\n", candidates[winner].name);

    return 0;
}