//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num_candidates, num_voters, max_votes = 0, winner_id;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // array to store candidate information
    struct candidate{
        int id;
        char name[50];
        int votes;
    }candidates[num_candidates];

    // array to store voter information
    struct voter{
        int id;
        int vote;
    }voters[num_voters];

    // get candidate information
    printf("\nEnter candidate information:\n");
    for(int i=0; i<num_candidates; i++){
        printf("\nCandidate %d:\n", i+1);
        candidates[i].id = i+1; // set candidate id
        printf("Enter name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // initialize vote count to zero
    }

    // get voter information
    printf("\nEnter voter information:\n");
    for(int i=0; i<num_voters; i++){
        printf("\nVoter %d:\n", i+1);
        voters[i].id = i+1; // set voter id
        printf("Enter vote for candidate (1-%d): ", num_candidates);
        scanf("%d", &voters[i].vote);
        while(voters[i].vote > num_candidates || voters[i].vote < 1){
            printf("Invalid vote! Enter vote for candidate (1-%d): ", num_candidates);
            scanf("%d", &voters[i].vote);
        }
        candidates[voters[i].vote-1].votes++; // increment vote count for candidate
    }

    // print results
    printf("\n\nELECTION RESULTS\n\n");
    for(int i=0; i<num_candidates; i++){
        printf("Candidate %d: %s\n", candidates[i].id, candidates[i].name);
        printf("Votes received: %d\n", candidates[i].votes);
        printf("-------------------------------------\n");
        if(candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
            winner_id = candidates[i].id;
        }
    }
    printf("\nWinner: Candidate %d", winner_id);

    return 0;
}