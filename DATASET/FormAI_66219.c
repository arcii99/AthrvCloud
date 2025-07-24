//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Voter struct
typedef struct Voter {
    char name[50];
    char voterID[20];
    int age;
    int vote;
} Voter;

// Function to add new voter to the system
void addVoter(Voter *voters, int *numVoters) {
    Voter newVoter;
    printf("Enter voter name:\n");
    scanf("%s", newVoter.name);
    printf("Enter voter ID:\n");
    scanf("%s", newVoter.voterID);
    printf("Enter voter age:\n");
    scanf("%d", &newVoter.age);
    newVoter.vote = -1;
    voters[*numVoters] = newVoter;
    (*numVoters)++;
}

// Function to display all voters in the system
void displayVoters(Voter *voters, int numVoters) {
    printf("Voter Name\tVoter ID\tVoter Age\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%s\t%s\t%d\n", voters[i].name, voters[i].voterID, voters[i].age);
    }
}

// Function to cast vote for a voter
void castVote(Voter *voters, int numVoters) {
    char voterID[20];
    printf("Enter voter ID to cast vote:\n");
    scanf("%s", voterID);
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            if (voters[i].vote != -1) {
                printf("This voter has already cast a vote.\n");
                return;
            }
            printf("Enter candidate number to cast vote:\n");
            scanf("%d", &voters[i].vote);
            printf("Vote cast successfully.\n");
            return;
        }
    }
    printf("No voter with the given ID found.\n");
}

// Function to display vote count for each candidate
void displayVoteCount(Voter *voters, int numVoters) {
    int numCandidates = 0;
    int *candidateVotes = NULL;
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].vote > numCandidates) {
            numCandidates = voters[i].vote;
        }
    }
    numCandidates++; // Add 1 to include candidate 0
    candidateVotes = (int*)calloc(numCandidates, sizeof(int));
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].vote != -1) {
            candidateVotes[voters[i].vote]++;
        }
    }
    printf("Candidate\tVote Count\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%d\n", i, candidateVotes[i]);
    }
    free(candidateVotes);
}

int main() {
    printf("Welcome to the Shape Shifting Electronic Voting System\n");
    printf("Please enter the number of voters:\n");
    int numVoters = 0;
    scanf("%d", &numVoters);
    Voter *voters = (Voter*)malloc(numVoters * sizeof(Voter));
    int choice = -1;
    while (choice != 0) {
        printf("Please select an option:\n");
        printf("1. Add new voter\n");
        printf("2. Display all voters\n");
        printf("3. Cast vote\n");
        printf("4. Display vote count\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addVoter(voters, &numVoters);
                break;
            case 2:
                displayVoters(voters, numVoters);
                break;
            case 3:
                castVote(voters, numVoters);
                break;
            case 4:
                displayVoteCount(voters, numVoters);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    free(voters);
    return 0;
}