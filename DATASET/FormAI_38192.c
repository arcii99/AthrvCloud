//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    int num_candidates = 0;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];
    for(int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters = 0;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int* votes = (int*)malloc(num_voters * sizeof(int));
    for(int i = 0; i < num_voters; i++) {
        printf("Enter the number of your preferred candidate (1-%d): ", num_candidates);
        scanf("%d", &votes[i]);

        if(votes[i] < 1 || votes[i] > num_candidates) {
            printf("Invalid candidate choice. Please choose a candidate between 1 and %d.\n", num_candidates);
            i--;
            continue;
        }
        candidates[votes[i] - 1].votes++;
    }

    printf("\nResults:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    free(votes);
    return 0;
}