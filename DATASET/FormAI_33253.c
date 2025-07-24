//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

struct candidate {
    char name[20];
    int num_votes;
};

struct voter {
    char name[20];
    int voted_for;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

void initialize_candidates(){
    for(int i=0; i<MAX_CANDIDATES; i++){
        candidates[i].name[0] = '\0';
        candidates[i].num_votes = 0;
    }
}

void initialize_voters(){
    for(int i=0; i<MAX_VOTERS; i++){
        voters[i].name[0] = '\0';
        voters[i].voted_for = -1;
    }
}

void add_candidate(char* name){
    for(int i=0; i<MAX_CANDIDATES; i++){
        if(candidates[i].name[0] == '\0'){
            strcpy(candidates[i].name, name);
            candidates[i].num_votes = 0;
            printf("Candidate %s added successfully\n", name);
            return;
        }
    }
    printf("Cannot add any more candidates\n");
}

void print_candidates(){
    printf("Candidates\n");
    for(int i=0; i<MAX_CANDIDATES; i++){
        if(candidates[i].name[0] != '\0'){
            printf("%d. %s\n", i+1, candidates[i].name);
        }
    }
}

int cast_vote(char* name, int candidate_num){
    for(int i=0; i<MAX_VOTERS; i++){
        if(strcmp(voters[i].name, name) == 0){
            if(voters[i].voted_for == -1){
                voters[i].voted_for = candidate_num;
                candidates[candidate_num-1].num_votes++;
                printf("Vote cast successfully\n");
                return 1;
            }
            else{
                printf("You have already voted\n");
                return 0;
            }
        }
    }
    printf("Voter not found\n");
    return 0;
}

void print_results(){
    printf("Results\n");
    for(int i=0; i<MAX_CANDIDATES; i++){
        if(candidates[i].name[0] != '\0'){
            printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].num_votes);
        }
    }
}

int main(){
    int option, candidate_num, num_voters=0;
    char name[20];
    initialize_candidates();
    initialize_voters();

    printf("Welcome to our Electronic Voting System!\n");

    while(1){
        printf("\nMenu:\n");
        printf("1. Add Candidate\n2. View Candidates\n3. Cast Vote\n4. View Results\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("\n");

        switch(option){
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                printf("Enter your name: ");
                scanf("%s", name);
                print_candidates();
                printf("Enter candidate number you want to vote for: ");
                scanf("%d", &candidate_num);
                if(candidate_num < 1 || candidate_num > MAX_CANDIDATES || candidates[candidate_num-1].name[0] == '\0'){
                    printf("Invalid candidate number\n");
                }
                else{
                    if(cast_vote(name, candidate_num)){
                        num_voters++;
                    }
                }
                break;
            case 4:
                if(num_voters == 0){
                    printf("No votes cast yet\n");
                }
                else{
                    print_results();
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}