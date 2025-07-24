//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 1000

// Voter structure
struct Voter {
    char name[50];
    int age;
    char gender[10];
    bool voted;
};

// Electronic Voting System structure
struct EVS {
    int totalVoters;
    struct Voter voters[MAX_VOTERS];
};

// Function to print the main menu
void printMainMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Register Voter\n");
    printf("2. Cast Vote\n");
    printf("3. Show Results\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to register a new voter
void registerVoter(struct EVS* evs) {
    printf("\nEnter Voter Details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", evs->voters[evs->totalVoters].name);
    printf("Age: ");
    scanf("%d", &evs->voters[evs->totalVoters].age);
    printf("Gender: ");
    scanf(" %[^\n]s", evs->voters[evs->totalVoters].gender);
    evs->voters[evs->totalVoters].voted = false;
    printf("\nVoter Registered Successfully!\n");
    evs->totalVoters++;
}

// Function to cast vote
void castVote(struct EVS* evs) {
    char choice;
    printf("\nCast Your Vote:\n");
    printf("A. Candidate A\n");
    printf("B. Candidate B\n");
    printf("C. Candidate C\n");
    printf("D. Candidate D\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'A':
            printf("You Voted for Candidate A\n");
            break;
        case 'B':
            printf("You Voted for Candidate B\n");
            break;
        case 'C':
            printf("You Voted for Candidate C\n");
            break;
        case 'D':
            printf("You Voted for Candidate D\n");
            break;
        default:
            printf("Invalid Choice\n");
            return;
    }

    // Marking the voter as voted
    for (int i = 0; i < evs->totalVoters; i++) {
        if (strcmp(evs->voters[i].name, "TEST VOTER") != 0 && !evs->voters[i].voted) {
            evs->voters[i].voted = true;
            printf("\nVote Casted Successfully!\n");
            break;
        }
    }
}

// Function to show election results
void showResults(struct EVS* evs) {
    int candidateA = 0, candidateB = 0, candidateC = 0, candidateD = 0;

    for (int i = 0; i < evs->totalVoters; i++) {
        if (evs->voters[i].voted) {
            char choice;
            printf("Voter Name: %s\n", evs->voters[i].name);
            printf("Gender: %s\n", evs->voters[i].gender);
            printf("Age: %d\n", evs->voters[i].age);
            printf("Vote: ");
            scanf(" %c", &choice);

            switch (choice) {
                case 'A':
                    candidateA++;
                    break;
                case 'B':
                    candidateB++;
                    break;
                case 'C':
                    candidateC++;
                    break;
                case 'D':
                    candidateD++;
                    break;
                default:
                    printf("Invalid Vote\n");
            }
        }
    }

    printf("\nElection Results:\n");
    printf("Candidate A: %d Votes\n", candidateA);
    printf("Candidate B: %d Votes\n", candidateB);
    printf("Candidate C: %d Votes\n", candidateC);
    printf("Candidate D: %d Votes\n", candidateD);
}

int main() {
    struct EVS evs;
    evs.totalVoters = 0;

    // Registering Test Voter
    strcpy(evs.voters[evs.totalVoters].name, "TEST VOTER");
    strcpy(evs.voters[evs.totalVoters].gender, "Male");
    evs.voters[evs.totalVoters].age = 18;
    evs.voters[evs.totalVoters].voted = false;
    evs.totalVoters++;

    int choice;
    do {
        printMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter(&evs);
                break;
            case 2:
                castVote(&evs);
                break;
            case 3:
                showResults(&evs);
                break;
            case 4:
                printf("Thank You for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    return 0;
}