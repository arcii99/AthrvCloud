//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CANDIDATES 20
#define MAX_NAME_LENGTH 50
#define MAX_VOTERS 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votedFor;
} Voter;

void getVoterDetails(int index, Voter* voter);
void getCandidateDetails(int index, Candidate* candidate);
int getChoice(const char *message, int min, int max);

int main() {
    int numCandidates;
    int numVoters;
    
    printf("Welcome to the Electronic Voting System!\n\n");
    
    numCandidates = getChoice("How many candidates are there?", 1, MAX_CANDIDATES);
    Candidate candidates[numCandidates];
    
    // Get candidate details from the user
    printf("\nPlease enter candidate details:\n");
    for (int i=0; i<numCandidates; i++) {
        getCandidateDetails(i, &candidates[i]);
    }
    
    numVoters = getChoice("\nHow many voters are there?", 1, MAX_VOTERS);
    Voter voters[numVoters];
    
    // Get voter details from the user
    printf("\nPlease enter voter details:\n");
    for (int i=0; i<numVoters; i++) {
        getVoterDetails(i, &voters[i]);
    }
    
    // Voting begins
    printf("\nVoting begins now!\nPlease enter the candidate number you want to vote for.\n");
    for (int i=0; i<numVoters; i++) {
        Voter voter = voters[i];
        int votedFor = voter.votedFor;
        
        if (votedFor >= 0) {
            printf("\n%s has already voted for %s.\n", voter.name, candidates[votedFor].name);
            continue;
        }
        
    vote:
        int choice = getChoice("Please enter your choice:", 1, numCandidates);
        candidates[choice-1].votes++;
        voter.votedFor = choice - 1;
        printf("Thanks for voting, %s!\n", voter.name);
        voters[i] = voter;
    }
        
    // Display election results
    printf("\nElection Results:\n");
    for (int i=0; i<numCandidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
    
    return 0;
}

void getVoterDetails(int index, Voter* voter) {
    printf("Enter name for voter %d: ", index+1);
    fgets(voter->name, MAX_NAME_LENGTH, stdin);
    strtok(voter->name, "\n");
    voter->votedFor = -1;
}

void getCandidateDetails(int index, Candidate* candidate) {
    printf("Enter name for candidate %d: ", index+1);
    fgets(candidate->name, MAX_NAME_LENGTH, stdin);
    strtok(candidate->name, "\n");
    candidate->votes = 0;
}

int getChoice(const char *message, int min, int max) {
    int choice = 0;
    char input[MAX_NAME_LENGTH];
    
    while (1) {
        printf("%s (%d-%d): ", message, min, max);
        fgets(input, MAX_NAME_LENGTH, stdin);
        sscanf(input, "%d", &choice);
        
        if (choice < min || choice > max) {
            printf("\nInvalid choice. Please try again.\n");
            continue;
        }
        break;
    }
    
    return choice;
}