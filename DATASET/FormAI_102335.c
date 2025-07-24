//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main()
{
    int voterCount, candidateCount;
    printf("Enter the number of voters: ");
    scanf("%d", &voterCount);
    printf("Enter the number of candidates: ");
    scanf("%d", &candidateCount);
    while (candidateCount > MAX_CANDIDATES || voterCount > MAX_VOTERS)
    {
        printf("Invalid input! Maximum number of candidates is %d and maximum number of voters is %d\n", MAX_CANDIDATES, MAX_VOTERS);
        printf("Enter the number of voters: ");
        scanf("%d", &voterCount);
        printf("Enter the number of candidates: ");
        scanf("%d", &candidateCount);
    }

    int voteMatrix[MAX_VOTERS][MAX_CANDIDATES], candidateTally[MAX_CANDIDATES];
    memset(candidateTally, 0, sizeof(candidateTally));
    memset(voteMatrix, 0, sizeof(voteMatrix));

    // Get the votes
    for (int i = 0; i < voterCount; i++)
    {
        printf("Voter %d, please make your selection:\n", i+1);
        for (int j = 0; j < candidateCount; j++)
        {
            printf("Enter 1 for candidate %d or 0 for no vote: ", j+1);
            scanf("%d", &voteMatrix[i][j]);
            if (voteMatrix[i][j] == 1)
            {
                candidateTally[j]++;
            }
        }
    }

    int highestVotes = 0, winnerIndex = -1, totalVotes = 0;

    // Get the winner
    for (int i = 0; i < candidateCount; i++)
    {
        totalVotes += candidateTally[i];
        if (candidateTally[i] > highestVotes)
        {
            highestVotes = candidateTally[i];
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1)
    {
        printf("The winner is candidate %d with %d votes\n", winnerIndex+1, highestVotes);
    }
    else
    {
        printf("There is no winner! Not enough votes were cast\n");
    }

    // Display the statistics
    printf("Total number of votes cast: %d\n", totalVotes);
    printf("Voter turnout: %.2f percent\n", (float)voterCount/MAX_VOTERS*100);
    printf("Candidate statistics:\n");
    for (int i = 0; i < candidateCount; i++)
    {
        printf("Candidate %d received %d votes (%.2f%%)\n", i+1, candidateTally[i], candidateTally[i]/(float)totalVotes*100);
    }

    return 0;
}