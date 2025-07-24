//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VOTERS 10000

struct Voter {
    char* name;
    int age;
    bool hasVoted;
};

struct Candidate {
    char* name;
    int votes;
};

int main() {
    struct Candidate candidates[5] = {
        {"John Doe", 0},
        {"Jane Smith", 0},
        {"Bob Johnson", 0},
        {"Maggie Lee", 0},
        {"Mike Thompson", 0}
    };

    struct Voter voters[MAX_VOTERS];

    int numVoters = 0;
    int numCandidates = 5;

    // Read in voter data
    FILE* fp = fopen("voters.txt", "r");
    if (fp == NULL) {
        printf("Error reading voters file\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, 100, fp)) {
        char* name = strtok(buffer, ",");
        int age = atoi(strtok(NULL, ","));

        struct Voter voter = {name, age, false};
        voters[numVoters++] = voter;
    }
    fclose(fp);

    // Allow voting
    printf("Welcome to the electronic voting system!\n");
    while (true) {
        printf("Enter your name to vote or 'exit' to quit: ");
        char name[100];
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        // Find voter by name
        struct Voter* voter = NULL;
        for (int i = 0; i < numVoters; i++) {
            if (strcmp(voters[i].name, name) == 0) {
                voter = &voters[i];
                break;
            }
        }
        if (voter == NULL) {
            printf("Sorry, you are not registered to vote\n");
            continue;
        }

        // Verify voter is old enough
        if (voter->age < 18) {
            printf("Sorry, you are not old enough to vote\n");
            continue;
        }

        // Verify voter hasn't already voted
        if (voter->hasVoted) {
            printf("Sorry, you have already voted\n");
            continue;
        }

        // Show candidates
        printf("Candidates:\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }

        // Vote for candidate
        printf("Enter the number of your chosen candidate: ");
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > numCandidates) {
            printf("Invalid choice\n");
            continue;
        }

        candidates[choice-1].votes++;
        voter->hasVoted = true;

        printf("Thank you for voting!\n");
    }

    // Print results
    printf("\nResults:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}