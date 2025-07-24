//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    char password[50];
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_CANDIDATES];
    int num_candidates, num_voters, num_voted = 0, i, j, voter_id = -1, selected_candidate = -1;
    char buffer[50], username_attempt[50], password_attempt[50];
    FILE *file;

    printf("Welcome to the Electronic Voting System\n");

    // Get number of candidates
    printf("Enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    fgets(buffer, 50, stdin);
    num_candidates = atoi(buffer);

    // Get candidate names
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        fgets(candidates[i].name, 50, stdin);
        candidates[i].votes = 0;
    }

    // Get number of voters
    printf("Enter the number of voters (up to %d): ", MAX_CANDIDATES);
    fgets(buffer, 50, stdin);
    num_voters = atoi(buffer);

    // Get voter usernames and passwords
    for (i = 0; i < num_voters; i++) {
        printf("Enter a username for voter %d: ", i+1);
        fgets(voters[i].username, 50, stdin);
        printf("Enter a password for voter %d: ", i+1);
        fgets(voters[i].password, 50, stdin);
    }

    // Login screen
    while (voter_id == -1) {
        printf("Enter your username: ");
        fgets(username_attempt, 50, stdin);
        printf("Enter your password: ");
        fgets(password_attempt, 50, stdin);

        // Check if voter exists and login credentials are correct
        for (i = 0; i < num_voters; i++) {
            if (strcmp(username_attempt, voters[i].username) == 0 && strcmp(password_attempt, voters[i].password) == 0) {
                printf("Login successful\n");
                voter_id = i;
                break;
            }
        }
        if (voter_id == -1) {
            printf("Login failed, please try again or contact an administrator if you believe this is in error\n");
        }
    }

    // Voting screen
    while (selected_candidate == -1) {
        printf("Please select a candidate by entering their number:\n");
        for (i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        fgets(buffer, 50, stdin);
        selected_candidate = atoi(buffer) - 1;
        if (selected_candidate < 0 || selected_candidate >= num_candidates) {
            printf("Invalid candidate selected, please try again\n");
            selected_candidate = -1;
        }
    }

    // Vote confirmation screen
    printf("Confirm selection of candidate %s? (y/n): ", candidates[selected_candidate].name);
    fgets(buffer, 50, stdin);
    if (buffer[0] == 'y' || buffer[0] == 'Y') {
        candidates[selected_candidate].votes++;
        num_voted++;
        printf("Thank you for voting\n");
    } else {
        printf("Voting cancelled, returning to login screen\n");
        voter_id = -1;
    }

    // Write results to file
    file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error writing results to file\n");
        return 1;
    }
    fprintf(file, "Results:\n");
    for (i = 0; i < num_candidates; i++) {
        fprintf(file, "%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    fprintf(file, "Total number of voters: %d\n", num_voted);
    fclose(file);

    printf("Results saved to file \"results.txt\"\n");

    return 0;
}