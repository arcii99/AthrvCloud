//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assume the maximum number of voters is 100
#define MAX_VOTERS 100

// Voter struct containing their ID and vote
typedef struct {
    int voter_id;
    int vote;
} Voter;

// Function to display the vote count for each candidate
void display_votes(int vote_count[]) {
    printf("\n\n");
    printf("Candidate 1: %d\n", vote_count[0]);
    printf("Candidate 2: %d\n", vote_count[1]);
    printf("Candidate 3: %d\n", vote_count[2]);
}

int main() {
    // Initialize the vote count for each candidate to 0
    int vote_count[3] = {0};

    // Initialize the list of voters
    Voter voters[MAX_VOTERS];
    int num_voters = 0;

    // Menu loop to allow the user to enter votes and display the vote count
    int choice;
    do {
        printf("\n\nElectronic Voting System\n");
        printf("1. Cast Vote\n");
        printf("2. Display Vote Count\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Ask for the voter ID
                int voter_id;
                printf("\nEnter your voter ID: ");
                scanf("%d", &voter_id);

                // Check if the voter has already voted
                int already_voted = 0;
                for (int i = 0; i < num_voters; i++) {
                    if (voters[i].voter_id == voter_id) {
                        already_voted = 1;
                        break;
                    }
                }

                if (already_voted) {
                    printf("\nYou have already cast your vote.\n");
                } else {
                    // Ask for the vote
                    int vote;
                    printf("Cast your vote:\n");
                    printf("1. Candidate 1\n");
                    printf("2. Candidate 2\n");
                    printf("3. Candidate 3\n");
                    printf("Enter your choice: ");
                    scanf("%d", &vote);

                    // Validate the vote
                    if (vote < 1 || vote > 3) {
                        printf("\nInvalid vote. Please try again.\n");
                    } else {
                        // Add the vote to the vote count and the list of voters
                        vote_count[vote-1]++;
                        voters[num_voters].voter_id = voter_id;
                        voters[num_voters].vote = vote;
                        num_voters++;
                        printf("\nThank you for casting your vote.\n");
                    }
                }
                break;
            case 2:
                // Display the vote count
                display_votes(vote_count);
                break;
            case 3:
                // Exit the program
                printf("\nThank you for using the Electronic Voting System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}