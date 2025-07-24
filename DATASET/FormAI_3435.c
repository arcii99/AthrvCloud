//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include<stdio.h>

struct candidate {
    char name[50];
    int votes;
};

int main() {

    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[num_candidates];

    for(int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for(int i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your choice (1-%d): ", i+1, num_candidates);
        int choice;
        scanf("%d", &choice);

        while(choice < 1 || choice > num_candidates) {
            printf("Invalid choice, please enter a choice from 1-%d: ", num_candidates);
            scanf("%d", &choice);
        }

        candidates[choice-1].votes++;
    }

    printf("The election results are as follows:\n");

    for(int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}