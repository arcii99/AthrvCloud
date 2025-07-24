//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 4

char candidates[MAX_CANDIDATES][20] = {"Knight A", "Knight B", "Knight C", "Knight D"};

typedef struct Voter {
    char name[20];
    int voted;
} Voter;

Voter voters[MAX_VOTERS];

void initializeVoters() {
    for(int i = 0; i < MAX_VOTERS; i++) {
        strcpy(voters[i].name, "");
        voters[i].voted = 0;
    }
}

void registerVoter(int index) {
    printf("Enter name of voter %d: ", index + 1);
    scanf("%s", voters[index].name);
    printf("Voter %d has been registered\n", index + 1);
}

void printCandidates() {
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
}

int castVote(int index) {
    int vote;
    printf("Dear %s, please select your candidate:\n", voters[index].name);
    printCandidates();
    scanf("%d", &vote);
    if(vote < 1 || vote > MAX_CANDIDATES) {
        printf("Invalid choice. Please try again.\n");
        return castVote(index);
    } else {
        voters[index].voted = vote;
        printf("Your vote for %s has been recorded. Thank you for voting!\n", candidates[vote - 1]);
        return 1;
    }
}

void countVotes() {
    int votes[MAX_CANDIDATES] = {0};
    for(int i = 0; i < MAX_VOTERS; i++) {
        if(voters[i].voted != 0) {
            votes[voters[i].voted - 1]++;
        }
    }
    printf("The election results are in!\n");
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }
}

int main() {
    int votersRegistered = 0;
    int voterAction = 0;
    initializeVoters();
    printf("Welcome to the Medieval Kingdom Election System!\n");
    while(voterAction != 2) {
        printf("What would you like to do?\n");
        printf("1. Register voter\n2. Cast votes\n");
        scanf("%d", &voterAction);
        if(voterAction == 1 && votersRegistered < MAX_VOTERS) {
            registerVoter(votersRegistered);
            votersRegistered++;
        } else if(voterAction == 1) {
            printf("Sorry, maximum number of voters have been registered.\n");
        } else if(voterAction == 2) {
            printf("Voting has begun!\n");
            for(int i = 0; i < MAX_VOTERS; i++) {
                if(voters[i].name[0] != '\0' && voters[i].voted == 0) {
                    castVote(i);
                }
            }
            countVotes();
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}