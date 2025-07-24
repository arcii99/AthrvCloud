//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VOTERS 10000
#define MAX_CANDIDATES 10

int main() {
    int num_voters, num_candidates;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    int votes[MAX_VOTERS];

    printf("Enter the votes of all voters (1-%d):\n", num_candidates);
    for (int i = 0; i < num_voters; i++) {
        printf("Vote of voter %d: ", i + 1);
        scanf("%d", &votes[i]);

        // Validate vote
        if (votes[i] < 1 || votes[i] > num_candidates) {
            printf("Invalid vote. Please enter a value between 1 and %d.\n", num_candidates);
            i--;
        }
    }

    int candidates[MAX_CANDIDATES] = {0};

    // Count the number of votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        candidates[votes[i] - 1]++;
    }

    // Determine the winner
    int winner = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i] > candidates[winner]) {
            winner = i;
        }
    }

    printf("The winner is candidate %d with %d votes.\n", winner + 1, candidates[winner]);

    return 0;
}