//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int candidates_count, voters_count;

    printf("Enter the number of candidates: ");
    scanf("%d", &candidates_count);
    
    printf("Enter the number of voters: ");
    scanf("%d", &voters_count);

    int* votes = (int*)calloc(candidates_count, sizeof(int));

    for (int i = 0; i < voters_count; i++)
    {
        printf("Voter %d\n", i+1);
        for (int j = 0; j < candidates_count; j++)
        {
            printf("Vote for candidate %d: ", j+1);
            int vote;
            scanf("%d", &vote);
            if (vote > 0 && vote <= candidates_count) votes[vote-1]++;
        }
        printf("\n");
    }

    printf("Voting results:\n");
    for (int i = 0; i < candidates_count; i++)
    {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }

    free(votes);
    return 0;
}