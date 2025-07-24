//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates and voters, and the filename which stores the list of candidates.
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define FILENAME "candidates.txt"

// Define a struct for candidates which contains the candidate name and the candidate vote count.
typedef struct {
    char name[50];
    int vote_count;
} candidate;

// Function to count the number of candidates in the specified file.
int count_candidates() {
    int count = 0;
    char buffer[50];

    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error: could not open file %s.\n", FILENAME);
        exit(1);
    }

    while (fgets(buffer, 50, file)) {
        count++;
    }

    fclose(file);

    return count;
}

// Function to load candidates from the specified file into an array of structs.
void load_candidates(candidate* candidates, int num_candidates) {
    char buffer[50];
    int i = 0;

    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error: could not open file %s.\n", FILENAME);
        exit(1);
    }

    while (fgets(buffer, 50, file)) {
        sscanf(buffer, "%s", candidates[i].name);
        candidates[i].vote_count = 0;
        i++;
    }

    fclose(file);
}

// Function to display the list of candidates.
void display_candidates(candidate* candidates, int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to record a vote for a candidate.
int vote(candidate* candidates, int num_candidates, int* voter_ids, int num_votes, int voter_id) {
    int candidate_num;

    do {
        printf("Enter the number of the candidate you wish to vote for: ");
        scanf("%d", &candidate_num);
    } while (candidate_num < 1 || candidate_num > num_candidates);

    // Check if this voter has already voted.
    for (int i = 0; i < num_votes; i++) {
        if (voter_ids[i] == voter_id) {
            printf("Error: you have already voted.\n");
            return num_votes;
        }
    }

    // Add the vote to the candidate's vote count.
    candidates[candidate_num-1].vote_count++;
    voter_ids[num_votes] = voter_id;

    printf("Vote recorded for %s.\n", candidates[candidate_num-1].name);

    return num_votes+1;
}

int main() {
    int num_candidates = count_candidates();
    int num_votes = 0;
    int voter_ids[MAX_VOTERS];
    candidate candidates[MAX_CANDIDATES];

    load_candidates(candidates, num_candidates);
    display_candidates(candidates, num_candidates);

    int voter_id;
    do {
        printf("Enter your voter ID (0 to quit): ");
        scanf("%d", &voter_id);

        if (voter_id > 0) {
            num_votes = vote(candidates, num_candidates, voter_ids, num_votes, voter_id);
        }
    } while (voter_id != 0);

    // Display the results.
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    return 0;
}