//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void displayResult(int, int);

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int candidate1_votes = 0, candidate2_votes = 0, num_voters = 0, rand_vote = 0;

    printf("Welcome to the post-apocalyptic electronic voting system.\n");

    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("\n");

    for (int i = 0; i < num_voters; i++) {
        rand_vote = rand() % 2; // Generate a random vote

        if (rand_vote == 0) { // Voter chose Candidate 1
            candidate1_votes++;
        } else { // Voter chose Candidate 2
            candidate2_votes++;
        }
    }

    // Display election results
    displayResult(candidate1_votes, candidate2_votes);

    return 0;
}

void displayResult(int candidate1_votes, int candidate2_votes) {
    printf("Election Results:\n");
    printf("-----------------\n");
    printf("Candidate 1: %d votes\n", candidate1_votes);
    printf("Candidate 2: %d votes\n", candidate2_votes);
    printf("-----------------\n");

    if (candidate1_votes > candidate2_votes) {
        printf("Candidate 1 wins the election!\n");
    } else if (candidate2_votes > candidate1_votes) {
        printf("Candidate 2 wins the election!\n");
    } else {
        printf("The election is a tie!\n");
    }
}