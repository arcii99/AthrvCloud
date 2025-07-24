//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 4
#define NUM_VOTERS 10

//Function to generate a random number between 0 and the given limit
int generate_random_number(int limit)
{
    srand(time(NULL));
    return rand() % limit;
}

//Function to print the results of the election
void print_election_results(int num_candidates, int votes[], char names[][30])
{
    int i, highest_vote_count = 0, winner_index = 0;

    //Find the candidate with the highest number of votes
    for(i=0; i<num_candidates; i++)
    {
        if(votes[i] > highest_vote_count)
        {
            highest_vote_count = votes[i];
            winner_index = i;
        }
    }

    //Print the winner
    printf("The winner of the election is %s with %d votes!\n", names[winner_index], highest_vote_count);

    //Print the results for all candidates
    printf("\nElection Results:\n");
    for(i=0; i<num_candidates; i++)
    {
        printf("%s: %d votes\n", names[i], votes[i]);
    }
}

int main()
{
    int i, j, vote;
    int votes[NUM_CANDIDATES] = {0};
    char candidate_names[NUM_CANDIDATES][30] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"};

    //Simulate voting process for each voter
    for(i=0; i<NUM_VOTERS; i++)
    {
        //Generate a random vote for each voter
        vote = generate_random_number(NUM_CANDIDATES);
        
        //Update the vote count for the candidate 
        votes[vote]++;
    }

    //Print the election results
    print_election_results(NUM_CANDIDATES, votes, candidate_names);

    return 0;
}