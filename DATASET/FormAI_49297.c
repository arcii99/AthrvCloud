//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

struct Voter {
    char name[50];
    int age;
    int voted;
    int candidateId;
};

struct Candidate {
    char name[50];
    int voteCount;
};

struct Voter voters[MAX_VOTERS];
struct Candidate candidates[MAX_CANDIDATES];

int numVoters = 0;
int numCandidates = 0;

void addCandidate(char name[]) {
    if (numCandidates < MAX_CANDIDATES) {
        strncpy(candidates[numCandidates].name, name, 50);
        candidates[numCandidates].voteCount = 0;
        numCandidates++;
        printf("Candidate added successfully.\n");
    } else {
        printf("Error: Maximum number of candidates has been reached.\n");
    }
}

void printCandidates() {
    printf("List of candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int vote(int voterId, int candidateId) {
    if (voters[voterId].voted) {
        printf("Error: This voter has already cast their vote.\n");
        return -1;
    } else if (candidateId < 1 || candidateId > numCandidates) {
        printf("Error: Invalid candidate ID.\n");
        return -1;
    } else {
        voters[voterId].voted = 1;
        voters[voterId].candidateId = candidateId;
        candidates[candidateId-1].voteCount++;
        printf("Vote cast successfully.\n");
        return 1;
    }
}

void printResults() {
    printf("Election results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].voteCount);
    }
}

void menu() {
    printf("Welcome to the Electronic Voting System.\n");
    int choice = 0;
    while (choice != 4) {
        printf("\nChoose an option:\n");
        printf("1. Add candidate\n");
        printf("2. Print list of candidates\n");
        printf("3. Cast vote\n");
        printf("4. Print election results\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the candidate: ");
                char candidateName[50];
                scanf("%s", candidateName);
                addCandidate(candidateName);
                break;
            case 2:
                printCandidates();
                break;
            case 3:
                printf("\nEnter your name: ");
                char voterName[50];
                scanf("%s", voterName);

                int voterAge = 0;
                while (voterAge < 18) {
                    printf("Enter your age (must be at least 18 years old): ");
                    scanf("%d", &voterAge);
                }

                int voterId = -1;
                for (int i = 0; i < numVoters; i++) {
                    if (strcmp(voters[i].name, voterName) == 0 && voters[i].age == voterAge) {
                        voterId = i;
                        break;
                    }
                }

                if (voterId == -1) {
                    printf("Error: You are not registered to vote.\n");
                } else {
                    int candidateId = 0;
                    while (candidateId < 1 || candidateId > numCandidates) {
                        printf("Choose a candidate by entering their ID (1-%d): ", numCandidates);
                        scanf("%d", &candidateId);
                    }
                    vote(voterId, candidateId);
                }
                break;
            case 4:
                printResults();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System.\n");
                break;
            default:
                printf("Error: Invalid choice, please try again.\n");
        }
    }
}

int main() {
    strncpy(candidates[0].name, "John Smith", 50);
    candidates[0].voteCount = 0;
    numCandidates++;

    strncpy(candidates[1].name, "Jane Doe", 50);
    candidates[1].voteCount = 0;
    numCandidates++;

    strncpy(voters[0].name, "Alice", 50);
    voters[0].age = 25;
    voters[0].voted = 0;
    numVoters++;

    strncpy(voters[1].name, "Bob", 50);
    voters[1].age = 20;
    voters[1].voted = 0;
    numVoters++;

    strncpy(voters[2].name, "Charlie", 50);
    voters[2].age = 30;
    voters[2].voted = 0;
    numVoters++;

    menu();

    return 0;
}