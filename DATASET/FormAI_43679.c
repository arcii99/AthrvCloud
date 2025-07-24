//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define NUM_CANDIDATES 4
#define NUM_VOTERS 100
#define MAX_VOTES 50

/* Function prototypes */
void initialize(int arr[NUM_CANDIDATES][NUM_VOTERS]);
void voting(int arr[NUM_CANDIDATES][NUM_VOTERS]);
void calculate(int arr[NUM_CANDIDATES][NUM_VOTERS]);

/* Main function */
int main()
{
    int votes[NUM_CANDIDATES][NUM_VOTERS] = {0};

    printf("Initializing voting system...\n");
    initialize(votes);
    printf("Voting is now open!\n");
    printf("Please cast your votes...\n");
    voting(votes);
    printf("Calculating results...\n");
    calculate(votes);
    return 0;
}

/* Function to initialize the array */
void initialize(int arr[NUM_CANDIDATES][NUM_VOTERS])
{
    srand(time(NULL)); // Seed the random number generator
    int i, j;
    for(i = 0; i < NUM_CANDIDATES; i++)
    {
        for(j = 0; j < NUM_VOTERS; j++)
        {
            arr[i][j] = rand() % MAX_VOTES + 1; // Random number of votes up to MAX_VOTES
        }
    }
}

/* Function for voters to cast their votes */
void voting(int arr[NUM_CANDIDATES][NUM_VOTERS])
{
    int i, j, vote;
    for(i = 0; i < NUM_VOTERS; i++)
    {
        printf("Voter #%d, please enter your vote:\n", i+1);
        for(j = 0; j < NUM_CANDIDATES; j++)
        {
            printf("Candidate %d: %d votes\n", j+1, arr[j][i]);
        }
        scanf("%d", &vote);
        arr[vote-1][i]++; // Increment the vote for the selected candidate
    }
}

/* Function to calculate the results */
void calculate(int arr[NUM_CANDIDATES][NUM_VOTERS])
{
    int i, j, total_votes, winner;
    float percent_vote;
    for(i = 0; i < NUM_CANDIDATES; i++)
    {
        total_votes = 0;
        for(j = 0; j < NUM_VOTERS; j++)
        {
            total_votes += arr[i][j]; // Calculate the total votes for each candidate
        }
        percent_vote = (float)total_votes / (float)(MAX_VOTES * NUM_VOTERS) * 100; // Calculate the percentage of total votes
        printf("Candidate %d: %d votes (%.2f%%)\n", i+1, total_votes, percent_vote);
        if(i == 0 || total_votes > winner)
        {
            winner = total_votes; // Set initial winner or update the winner if a new candidate has more votes
        }
    }
    printf("The winner is candidate ");
    for(i = 0; i < NUM_CANDIDATES; i++)
    {
        if(total_votes == winner)
        {
            printf("%d\n", i+1); // Print the winning candidate(s)
        }
    }
}