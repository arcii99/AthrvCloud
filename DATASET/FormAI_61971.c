//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
/* Romeo and Juliet C Electronic Voting System Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char candidates[5][30] = {"Romeo", "Juliet", "Paris", "Benvolio", "Tybalt"};
    int votes[5] = {0, 0, 0, 0, 0};
    int numVoters, i, j, choice;
    char confirm;

    printf("Welcome to the Electronic Voting System of Fair Verona!\n");
    printf("Please enter the number of registered voters: ");
    scanf("%d", &numVoters);

    for (i = 1; i <= numVoters; i++)
    {
        printf("\nVoter %d, please enter your choice:\n", i);
        for (j = 0; j < 5; j++)
        {
            printf("%d. %s\n", j+1, candidates[j]);
        }
        scanf("%d", &choice);
        votes[choice-1]++;
        printf("%s, are you sure you want to vote for %s? (Y/N)\n", candidates[choice-1], candidates[choice-1]);
        getchar();
        scanf("%c", &confirm);
        if (confirm == 'N' || confirm == 'n')
        {
            votes[choice-1]--;
            printf("Please re-enter your choice:\n");
            scanf("%d", &choice);
            votes[choice-1]++;
        }
    }

    printf("\n*** Voting Results ***\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    return 0;
}