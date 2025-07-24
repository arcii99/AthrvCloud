//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int voter_id, vote, vote_count_a = 0, vote_count_b = 0;

    printf("Welcome to the Electronic Voting System\n\n");

    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    srand(time(0));
    printf("\nCandidate List:\n");
    printf("1. Candidate A\n2. Candidate B\n");

    printf("\nPress 1 to vote for Candidate A\nPress 2 to vote for Candidate B\n");
    scanf("%d", &vote);

    switch(vote) {
        case 1:
            vote_count_a++;
            printf("\nThank you for casting your vote!\n");
            break;
        case 2:
            vote_count_b++;
            printf("\nThank you for casting your vote!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    printf("\nYour vote has been recorded as follows:\n");
    printf("Voter ID: %d\n", voter_id);
    printf("Vote: Candidate %c", vote == 1 ? 'A' : 'B');

    printf("\n\nVote count so far:\nCandidate A - %d\nCandidate B - %d\n", vote_count_a, vote_count_b);

    return 0;
}