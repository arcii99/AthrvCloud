//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct candidate {
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_of_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_of_candidates);
    Candidate candidates[num_of_candidates];
    for (int i=0; i<num_of_candidates; i++) {
        printf("Candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    int num_of_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_of_voters);
    for (int i=0; i<num_of_voters; i++) {
        int choice;
        printf("Voter %d, choose a candidate:\n", i+1);
        for (int j=0; j<num_of_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        scanf("%d", &choice);
        candidates[choice-1].votes++;
        printf("Thank you for your vote!\n");
    }
    printf("\nResults:\n");
    int max_votes = 0;
    int winner_index = 0;
    for (int i=0; i<num_of_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("\nThe winner is: %s!\n", candidates[winner_index].name);
    return 0;
}