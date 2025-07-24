//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>

// Voters struct
typedef struct {
    char name[50];
    int age;
} Voter;

// Candidates struct
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to display menu and get user input
char getMenuInput() {
    printf("\nELECTRONIC VOTING SYSTEM\n");
    printf("1. Cast Vote\n");
    printf("2. View Election Results\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
    
    char choice;
    scanf(" %c", &choice);
    return choice;
}

// Function to cast vote
void castVote(Voter voters[], Candidate candidates[], int numVoters, int numCandidates) {
    printf("\nCAST YOUR VOTE\n");
    printf("Enter your name: ");
    
    char name[50];
    scanf("%s", name);
    
    // Find the voter in the voters array
    int voterIndex = -1;
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            voterIndex = i;
            break;
        }
    }
    
    // If the voter is not found, exit the function
    if (voterIndex == -1) {
        printf("Voter not found.\n");
        return;
    }
    
    // If the voter has already voted, exit the function
    if (voters[voterIndex].age != -1) {
        printf("You have already cast your vote.\n");
        return;
    }
    
    // Display the list of candidates
    printf("\nCANDIDATES\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    
    printf("Enter your choice (1-%d): ", numCandidates);
    int candidateChoice;
    scanf("%d", &candidateChoice);
    
    // Increment the candidate vote count
    candidates[candidateChoice-1].votes++;
    
    // Mark the voter as voted
    voters[voterIndex].age = 1;
    
    printf("Thank you for casting your vote!\n");
}

// Function to display election results
void viewElectionResults(Candidate candidates[], int numCandidates) {
    printf("\nELECTION RESULTS\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize voters
    Voter voters[5];
    strcpy(voters[0].name, "John");
    voters[0].age = -1;
    strcpy(voters[1].name, "Jane");
    voters[1].age = -1;
    strcpy(voters[2].name, "Bob");
    voters[2].age = -1;
    strcpy(voters[3].name, "Alice");
    voters[3].age = -1;
    strcpy(voters[4].name, "Tom");
    voters[4].age = -1;
    
    // Initialize candidates
    Candidate candidates[3];
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].votes = 0;
    
    while (1) {
        char choice = getMenuInput();
        
        switch (choice) {
            case '1':
                castVote(voters, candidates, 5, 3);
                break;
            case '2':
                viewElectionResults(candidates, 3);
                break;
            case '3':
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}