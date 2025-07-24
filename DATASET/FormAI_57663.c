//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int candidates, voters;

    printf("Enter the number of candidates: ");
    scanf("%d", &candidates);

    printf("\nEnter the number of voters: ");
    scanf("%d", &voters);

    int votes[candidates];
    char candidate_names[candidates][20];

    for(int i = 0; i < candidates; i++){
        printf("\nEnter name of candidate %d: ", i+1);
        scanf("%s", &candidate_names[i]);
        votes[i] = 0;
    }

    srand(time(0));

    int voter_id, rand_vote;
    for(int i = 0; i < voters; i++){
        voter_id = i+1;
        rand_vote = rand() % candidates;
        votes[rand_vote]++;
        printf("\nVoter %d has voted for %s", voter_id, candidate_names[rand_vote]);
    }

    int max_votes = 0, winner_index = 0;
    for(int i = 0; i < candidates; i++){
        if(votes[i] > max_votes){
            max_votes = votes[i];
            winner_index = i;
        }
    }

    printf("\n\nCandidate with highest votes is %s with %d votes.\n\n", candidate_names[winner_index], max_votes);

    return 0;
}