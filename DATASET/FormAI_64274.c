//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

int main(){
    char candidate_list[MAX_CANDIDATES][20] = {"John", "Sarah", "David", "Michael", "Jessica"};
    int vote_count[MAX_CANDIDATES] = {0, 0, 0, 0, 0};
    char voter_list[MAX_VOTERS][20];
    int num_voters = 0;
    int num_candidates = 5;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name to vote: ");
    scanf("%s", voter_list[0]);
    printf("\nCandidates: \n");
    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", i+1, candidate_list[i]);
    }
    printf("\n");

    int vote = 0;
    while(1){
        printf("Enter your vote (1-%d) or type 0 to finish voting: ", num_candidates);
        scanf("%d", &vote);
        if(vote == 0){
            break;
        }
        else if(vote > num_candidates || vote < 0){
            printf("Invalid candidate number, please try again.\n");
            continue;
        }
        else{
            vote_count[vote-1]++;
            printf("Thank you for your vote!\n");
        }
    }

    printf("Voting has ended. Here are the results: \n");
    for(int i=0; i<num_candidates; i++){
        printf("%s: %d votes.\n", candidate_list[i], vote_count[i]);
    }

    return 0;
}