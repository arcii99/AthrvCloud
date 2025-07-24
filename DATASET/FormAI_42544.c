//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    Candidate *candidates = malloc(num_candidates * sizeof(Candidate));
    for(int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    int *voted_candidates = calloc(num_voters, sizeof(int));
    for(int i = 0; i < num_voters; i++) {
        printf("Enter candidate number you want to vote for: ");
        int candidate_num;
        scanf("%d", &candidate_num);
        while(candidate_num < 1 || candidate_num > num_candidates || voted_candidates[candidate_num-1]) {
            printf("Invalid candidate, please enter a valid number: ");
            scanf("%d", &candidate_num);
        }
        voted_candidates[candidate_num-1] = 1;
        candidates[candidate_num-1].votes++;
    }
    printf("Results:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    free(candidates);
    free(voted_candidates);
    return 0;
}