//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, v, n, m;
    int candidate_count, voter_count;
    int candidate_votes[1000] = { 0 };
    int voter_choices[1000][1000] = { 0 };
    int voter_rankings[1000][1000] = { 0 };

    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);

    for (i = 0; i < candidate_count; i++) {
        printf("Enter the name of candidate #%d: ", i+1);
        // Code to get candidate name from user and store in an array
    }

    for (i = 0; i < voter_count; i++) {
        printf("Enter the choices for voter #%d (separated by spaces): ", i+1);
        // Code to get voter choices from user and store in a 2D array
    }

    // Count the number of votes for each candidate
    for (i = 0; i < voter_count; i++) {
        for (j = 0; j < candidate_count; j++) {
            candidate_votes[voter_choices[i][j]]++;
        }
    }

    // Find the candidate(s) with the most votes
    int max_votes = 0;
    for (i = 0; i < candidate_count; i++) {
        if (candidate_votes[i] > max_votes) {
            max_votes = candidate_votes[i];
        }
    }

    // If there is only one candidate with the most votes, that candidate wins
    int winner;
    for (i = 0; i < candidate_count; i++) {
        if (candidate_votes[i] == max_votes) {
            winner = i;
            break;
        }
    }

    // If multiple candidates have the most votes, perform a run-off election
    if (winner == -1) {
        while (1) {
            // Count the number of votes for each candidate in the run-off
            for (i = 0; i < candidate_count; i++) {
                candidate_votes[i] = 0;
            }
            for (i = 0; i < voter_count; i++) {
                for (j = 0; j < candidate_count && voter_rankings[i][j] != -1; j++) {
                    if (voter_rankings[i][j] == winner) {
                        break;
                    }
                    candidate_votes[voter_rankings[i][j]]++;
                }
            }

            // Find the candidate(s) with the most votes in the run-off
            max_votes = 0;
            for (i = 0; i < candidate_count; i++) {
                if (candidate_votes[i] > max_votes) {
                    max_votes = candidate_votes[i];
                }
            }

            // If there is only one candidate with the most votes, that candidate wins the run-off
            int run_off_winner;
            for (i = 0; i < candidate_count; i++) {
                if (candidate_votes[i] == max_votes) {
                    run_off_winner = i;
                    break;
                }
            }

            // If multiple candidates have the most votes in the run-off, continue the run-off
            if (run_off_winner == -1) {
                printf("No candidate has a majority of the votes. Performing run-off between the following candidates:\n");
                for (i = 0; i < candidate_count; i++) {
                    if (candidate_votes[i] == max_votes) {
                        printf("Candidate %d\n", i+1);
                    }
                }
                printf("\n");
                winner = -1;
            } else {
                printf("Candidate %d has won the election.\n", run_off_winner+1);
                winner = run_off_winner;
                break;
            }
        }
    } else {
        printf("Candidate %d has won the election.\n", winner+1);
    }
    return 0;
}