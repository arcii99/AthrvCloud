//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>

#define MAX_VOTERS 100

int main()
{
    char candidates[5][20] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D", "Candidate E"};
    int votes[5] = {0};
    char voterNames[MAX_VOTERS][20];
    int voterIDs[MAX_VOTERS];
    int numVoters = 0;

    while(numVoters < MAX_VOTERS)
    {
        printf("Enter Voter Name: ");
        scanf("%s", voterNames[numVoters]);
        printf("Enter Voter ID: ");
        scanf("%d", &voterIDs[numVoters]);

        int candidateChoice = 0;
        printf("Enter Candidate Choice (1-5):\n");
        for(int i = 0; i < 5; i++)
        {
            printf("%d. %s\n", i+1, candidates[i]);
        }
        scanf("%d", &candidateChoice);

        votes[candidateChoice-1]++;
        printf("Thank you for your vote!\n\n");

        char anotherVote;
        printf("Is there another voter? (y/n) ");
        scanf(" %c", &anotherVote);
        if(anotherVote == 'n')
        {
            break;
        }

        numVoters++;
    }

    printf("\n----- RESULT -----\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    return 0;
}