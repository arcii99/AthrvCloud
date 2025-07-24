//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int votes[3] = {0}; // initialize votes for candidates 1, 2, and 3 to 0
    int vote; // initialize variable for user input
    int max_votes = 0; // initialize variable for tracking the maximum votes

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please choose the candidate you want to vote for by entering the corresponding number:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");
    printf("Enter -1 to exit the voting system.\n");

    while (1) {
        printf("Vote: ");
        scanf("%d", &vote);

        if (vote == -1) { // user inputs -1 to exit
            printf("Thank you for voting!\n");
            break;
        }

        if (vote >= 1 && vote <= 3) { // user inputs valid vote
            votes[vote - 1]++; // increment vote for candidate corresponding to user input
            printf("Vote recorded for Candidate %c.\n", vote + 64);
        } else { // user inputs invalid vote
            printf("Invalid vote. Please choose a candidate by entering a number from 1 to 3.\n");
        }
    }

    printf("\nHere are the voting results:\n");

    for (int i = 0; i < 3; i++) {
        printf("Candidate %c: %d votes\n", i + 65, votes[i]); // print out votes for each candidate
        if (votes[i] > max_votes) { // track maximum votes 
            max_votes = votes[i];
        }
    }

    int max_counter = 0; // initialize counter for multiple candidates with maximum votes
    
    for (int i = 0; i < 3; i++) {
        if (votes[i] == max_votes) { // check if candidate has maximum votes
            max_counter++; // increment counter if candidate has maximum votes
        }
    }

    if (max_counter == 1) { // only one candidate has maximum votes
        printf("\nThe winner is Candidate %c with %d votes!\n", votes[max_votes - 1], max_votes);
    } else { // multiple candidates have maximum votes
        printf("\nThere was a tie! The following candidates each received %d votes:\n", max_votes);
        for (int i = 0; i < 3; i++) {
            if (votes[i] == max_votes) {
                printf("Candidate %c\n", i + 65); // print out names of candidates with maximum votes
            }
        }
    }

    return 0;
}