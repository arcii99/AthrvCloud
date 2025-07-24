//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j, num_votes;
    char candidate_name[20][100], candidate_code[20][20];
    float candidate_votes[20];

    printf("Enter the number of candidates participating: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("\nEnter the candidate name: ");
        scanf("%s", candidate_name[i]);
        printf("\nEnter the candidate code: ");
        scanf("%s", candidate_code[i]);
    }

    printf("\nEnter the number of votes: ");
    scanf("%d", &num_votes);

    char vote_code[20];
    for (i=0; i<num_votes; i++) {
        printf("\nEnter the vote code for vote %d: ", i+1);
        scanf("%s", vote_code);
        for (j=0; j<n; j++) {
            if (strcmp(vote_code, candidate_code[j]) == 0) {
                candidate_votes[j]++;
                break;
            }
        }
    }

    printf("\nCandidate\t\tVotes\t\tPercentage");

    for (i=0; i<n; i++) {
        printf("\n%s\t\t%.0f\t\t%.2f%%", candidate_name[i], candidate_votes[i], (candidate_votes[i]/num_votes)*100);
    }

    return 0;
}