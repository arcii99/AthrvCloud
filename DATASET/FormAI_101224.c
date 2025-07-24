//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The number of candidates
#define CANDIDATE_COUNT 4

// The number of voters
#define VOTER_COUNT 100

// The maximum length of candidate name
#define NAME_MAX_LENGTH 30

// The maximum length of password
#define PASSWORD_MAX_LENGTH 20

// The maximum number of wrong password attempts
#define MAX_WRONG_PASSWORD_ATTEMPTS 3

// The structure of a candidate 
typedef struct {
    char name[NAME_MAX_LENGTH];
    int vote_count;
} Candidate;

// The structure of a voter
typedef struct {
    char name[NAME_MAX_LENGTH];
    char password[PASSWORD_MAX_LENGTH];
    int voted_candidate_index;
} Voter;

// The array of candidates
Candidate candidates[CANDIDATE_COUNT];

// The array of voters
Voter voters[VOTER_COUNT];

// The function to initialize candidates
void init_candidates() {
    strcpy(candidates[0].name, "John Smith");
    candidates[0].vote_count = 0;
    
    strcpy(candidates[1].name, "Jane Doe");
    candidates[1].vote_count = 0;
    
    strcpy(candidates[2].name, "Bob Johnson");
    candidates[2].vote_count = 0;
    
    strcpy(candidates[3].name, "Alice Williams");
    candidates[3].vote_count = 0;
}

// The function to initialize voters
void init_voters() {
    for (int i = 0; i < VOTER_COUNT; i++) {
        sprintf(voters[i].name, "Voter %d", i + 1);
        sprintf(voters[i].password, "password%d", i + 1);
        voters[i].voted_candidate_index = -1;
    }
}

// The function to get the candidate index by name
int get_candidate_index_by_name(char* name) {
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// The function to get the voter index by name
int get_voter_index_by_name(char* name) {
    for (int i = 0; i < VOTER_COUNT; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// The function to vote
void vote(char* voter_name, char* candidate_name) {
    int candidate_index = get_candidate_index_by_name(candidate_name);
    if (candidate_index == -1) {
        printf("Error: Candidate not found.\n");
        return;
    }
    
    int voter_index = get_voter_index_by_name(voter_name);
    if (voter_index == -1) {
        printf("Error: Voter not found.\n");
        return;
    }
    
    if (voters[voter_index].voted_candidate_index != -1) {
        printf("Error: This voter has already voted.\n");
        return;
    }
    
    printf("Please enter your password: ");
    char password[PASSWORD_MAX_LENGTH];
    scanf("%s", password);
    
    if (strcmp(password, voters[voter_index].password) != 0) {
        printf("Error: Wrong password.\n");
        return;
    }
    
    printf("You have voted for %s.\n", candidate_name);
    candidates[candidate_index].vote_count++;
    voters[voter_index].voted_candidate_index = candidate_index;
}

// The function to print the result
void print_result() {
    printf("Result:\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%s: %d votes.\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    srand(time(NULL));
    init_candidates();
    init_voters();
    
    while (1) {
        printf("Please enter your name (or 'exit' to quit): ");
        char name[NAME_MAX_LENGTH];
        scanf("%s", name);
        
        if (strcmp(name, "exit") == 0) {
            break;
        }
        
        int voter_index = get_voter_index_by_name(name);
        if (voter_index == -1) {
            printf("Error: Voter not found.\n");
            continue;
        }
        
        printf("Please enter your password: ");
        char password[PASSWORD_MAX_LENGTH];
        scanf("%s", password);
        
        if (strcmp(password, voters[voter_index].password) != 0) {
            printf("Error: Wrong password.\n");
            continue;
        }
        
        if (voters[voter_index].voted_candidate_index != -1) {
            printf("You have already voted.\n");
            print_result();
            continue;
        }
        
        printf("Welcome to the voting system. Please choose your candidate:\n");
        for (int i = 0; i < CANDIDATE_COUNT; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
        printf("Enter your choice (1-%d): ", CANDIDATE_COUNT);
        int choice = 0;
        scanf("%d", &choice);
        if (choice < 1 || choice > CANDIDATE_COUNT) {
            printf("Error: Invalid choice.\n");
            continue;
        }
        
        vote(name, candidates[choice - 1].name);
    }
    
    print_result();
    
    return 0;
}