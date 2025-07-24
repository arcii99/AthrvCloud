//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 5
#define VOTER_COUNT 10

int candidateVotes[CANDIDATE_COUNT] = {0};
int voterList[VOTER_COUNT] = {0};

void displayMenu() {
    printf("\n------ Electronic Voting System ------\n");
    printf("1. Display Candidates\n");
    printf("2. Vote for a Candidate\n");
    printf("3. Display Voting Results\n");
    printf("4. Quit Program\n");
    printf("Enter your choice (1-4): ");
}

void displayCandidates() {
    printf("\n------ Candidates List ------\n");
    printf("1. John Doe\n");
    printf("2. Jane Smith\n");
    printf("3. Michael Johnson\n");
    printf("4. Sarah Lee\n");
    printf("5. Joseph Kim\n");
}

int castVote(int voterID) {
    int candidateChoice;

    do {
        printf("\nEnter candidate number to vote for (1-5): ");
        scanf("%d", &candidateChoice);
    } while (candidateChoice < 1 || candidateChoice > CANDIDATE_COUNT);

    candidateVotes[candidateChoice - 1]++;
    voterList[voterID] = 1;

    printf("\nThank you for voting!");

    return candidateChoice;
}

void displayResults() {
    int i, winnerIndex = 0, totalVotes = 0;

    printf("\n------ Voting Results ------\n");

    for (i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%d. Candidate %d - Votes: %d\n", i+1, i+1, candidateVotes[i]);
        if (candidateVotes[i] > candidateVotes[winnerIndex]) {
            winnerIndex = i;
        }
        totalVotes += candidateVotes[i];
    }

    printf("\nTotal Votes Cast: %d", totalVotes);

    if (totalVotes == 0) {
        printf("\nNo votes were cast in this election.");
    } else {
        printf("\n\nWinner: Candidate %d", winnerIndex + 1);
    }
}

int main() {
    int i, choice, voterID;

    // Initialize random seed
    srand(time(0));

    // Assign random voter IDs
    for (i = 0; i < VOTER_COUNT; i++) {
        voterList[i] = rand() % 2;
    }

    // Main program loop
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCandidates();
                break;
            case 2:
                printf("\nEnter your Voter ID: ");
                scanf("%d", &voterID);

                if (voterList[voterID] == 1) {
                    printf("\nYou have already cast your vote.");
                } else {
                    castVote(voterID);
                }

                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("\nProgram successfully ended.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a choice between 1 and 4.");
                break;
        }
    } while (choice != 4);

    return 0;
}