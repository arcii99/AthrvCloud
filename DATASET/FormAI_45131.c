//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

char *candidate_names[MAX_CANDIDATES] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D", "Candidate E", "Candidate F", "Candidate G", "Candidate H", "Candidate I", "Candidate J"};
int num_candidates = 3;

typedef struct voter{
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    int voted_for;
} Voter;

Voter voters[MAX_VOTERS];
int num_voters = 0;

void registerVoter();
void castVote(int);
void showResults();
void clearScreen();
void printMenu();

int main(){
    int i, choice, vote;
    for(i=0; i<num_candidates; i++){
        candidate_names[i] = strdup(candidate_names[i]);
    }
    while(1){
        clearScreen();
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                registerVoter();
                break;
            case 2:
                printf("\nEnter the candidate number you want to vote for: ");
                scanf("%d", &vote);
                castVote(vote);
                break;
            case 3:
                showResults();
                break;
            case 4:
                printf("\nTerminating the program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
        printf("\nPress any key to continue...");
        getchar();
        getchar();
    }
}

void registerVoter(){
    Voter v;
    printf("\nEnter voter's name: ");
    scanf("%s", v.name);
    printf("\nEnter voter's age: ");
    scanf("%d", &v.age);
    printf("\nEnter voter's gender (M/F): ");
    scanf(" %c", &v.gender);
    v.voted_for = -1;
    voters[num_voters++] = v;
    printf("\nVoter registered successfully!\n");
}

void castVote(int vote){
    if(vote > num_candidates || vote < 1){
        printf("\nInvalid candidate number, please try again.\n");
    }else{
        int i, current_voter;
        for(i=0; i<num_voters; i++){
            if(strcmp(voters[i].name, "") == 0){
                current_voter = i;
                break;
            }
        }
        voters[current_voter].voted_for = vote;
        printf("\nThank you for voting!\n");
    }
}

void showResults(){
    int i, j;
    int count_votes[MAX_CANDIDATES] = {0};
    for(i=0; i<num_candidates; i++){
        for(j=0; j<num_voters; j++){
            if(voters[j].voted_for == i+1){
                count_votes[i]++;
            }
        }
    }
    clearScreen();
    printf("\n");
    for(i=0; i<num_candidates; i++){
        printf("%s : %d votes\n", candidate_names[i], count_votes[i]);
    }
}

void clearScreen(){
    #ifdef WINDOWS
        system("cls");
    #else
        printf("\033[H\033[J");
    #endif
}

void printMenu(){
    printf("\nElectronic Voting System\n");
    printf("\n1. Register voter\n");
    printf("2. Cast vote\n");
    printf("3. Show results\n");
    printf("4. Quit\n");
}