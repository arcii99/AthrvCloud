//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 20

struct candidate {
    char name[50];
    int votes;
};

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates, num_votes = 0;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Voting starts now. Please enter the number of votes to cast: ");
    scanf("%d", &num_votes);

    for (int i = 0; i < num_votes; i++) {
        printf("Vote %d\n", i+1);
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        int selected;
        printf("Select candidate number: ");
        scanf("%d", &selected);
        if (selected < 1 || selected > num_candidates) {
            printf("Invalid selection. Please try again.\n");
            i--;
            continue;
        }
        candidates[selected-1].votes++;
    }

    printf("Voting has ended. Here are the results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}