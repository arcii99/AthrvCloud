//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

// Global arrays to store candidate names and vote count
char candidate_names[NUM_CANDIDATES][20] = {"Candidate 1", "Candidate 2", "Candidate 3", "Candidate 4", "Candidate 5"};
int vote_count[NUM_CANDIDATES] = {0};

// Function to display list of candidates
void display_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidate_names[i]);
    }
}

// Function to get vote from a voter
void get_vote(int voter_num) {
    char choice[10];
    int candidate_num;
    printf("Voter %d, please vote for a candidate (enter candidate number): ", voter_num+1);
    scanf("%s", choice);
    candidate_num = atoi(choice);
    if (candidate_num >= 1 && candidate_num <= NUM_CANDIDATES) {
        vote_count[candidate_num-1]++;
        printf("Thank you for your vote!\n");
    } else {
        printf("Invalid choice, please try again.\n");
        get_vote(voter_num);
    }
}

// Function to display vote count for each candidate
void display_results() {
    printf("Vote count for each candidate:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidate_names[i], vote_count[i]);
    }
}

// Main function
int main() {
    // Display list of candidates
    display_candidates();
    
    // Get votes from all voters
    for (int i = 0; i < NUM_VOTERS; i++) {
        get_vote(i);
    }
    
    // Display final results
    display_results();
    
    return 0;
}