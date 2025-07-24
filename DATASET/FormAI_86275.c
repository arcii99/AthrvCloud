//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create struct for candidate information
typedef struct Candidate {
    char name[30];
    int votes;
} Candidate;

// Create struct for election information
typedef struct Election {
    char topic[50];
    Candidate candidates[10];
    int num_candidates;
    int num_votes;
} Election;

int main() {
    // Initialize election struct and set defaults
    Election election;
    strcpy(election.topic, "2021 Presidential Election");
    election.num_candidates = 3;
    election.num_votes = 0;
    
    // Initialize candidate structs and set defaults
    Candidate candidate1, candidate2, candidate3;
    strcpy(candidate1.name, "Joe Biden");
    candidate1.votes = 0;
    strcpy(candidate2.name, "Donald Trump");
    candidate2.votes = 0;
    strcpy(candidate3.name, "Kanye West");
    candidate3.votes = 0;
    
    // Add candidates to election struct
    election.candidates[0] = candidate1;
    election.candidates[1] = candidate2;
    election.candidates[2] = candidate3;
    
    // Print election information
    printf("Welcome to the %s\n", election.topic);
    printf("The candidates are:\n");
    for(int i = 0; i < election.num_candidates; i++) {
        printf("%s\n", election.candidates[i].name);
    }
    
    // Loop through voting process until it is ended
    int end_voting = 0;
    while(!end_voting) {
        char voter_choice[30];
        printf("Enter your vote (or type 'done' to end voting): ");
        fgets(voter_choice, 30, stdin);
        voter_choice[strcspn(voter_choice, "\n")] = 0;
        if(strcmp(voter_choice, "done") == 0) {
            end_voting = 1;
        } else {
            int found_candidate = 0;
            for(int i = 0; i < election.num_candidates; i++) {
                if(strcmp(voter_choice, election.candidates[i].name) == 0) {
                    election.candidates[i].votes++;
                    election.num_votes++;
                    found_candidate = 1;
                    break;
                }
            }
            if(!found_candidate) {
                printf("Error: Candidate not found\n");
            }
        }
    }
    
    // Print election results
    printf("Results:\n");
    for(int i = 0; i < election.num_candidates; i++) {
        double percent_votes = (double)election.candidates[i].votes / election.num_votes * 100;
        printf("%s: %d votes (%.2f%%)\n", election.candidates[i].name, election.candidates[i].votes, percent_votes);
    }
    
    return 0;
}