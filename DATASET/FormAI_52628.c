//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include<stdio.h>
#include<string.h>

int main()
{
    int votersCount = 0;
    int yesCount = 0, noCount = 0;
    char voterName[30];

    printf("Welcome to the Electronic Voting System!\n");
    printf("---------------------------------------\n");

    printf("Enter the number of voters: ");
    scanf("%d", &votersCount);

    for(int i = 1; i <= votersCount; i++)
    {
        printf("\nEnter the name of voter %d: ", i);
        scanf("%s", voterName);

        // Check if the voter has already voted
        if(checkVoter(voterName))
        {
            printf("\nSorry, %s has already casted their vote.\n", voterName);
            i--;
        }
        else
        {
            printf("\nPlease cast your vote for the given option:\n");
            printf("1. YES\n2. NO\n");

            int vote;
            scanf("%d", &vote);

            // Validate vote
            if(vote == 1)
            {
                yesCount++;
                printf("\nThank you for casting your vote, %s!\n", voterName);
                addVoter(voterName);
            }
            else if(vote == 2)
            {
                noCount++;
                printf("\nThank you for casting your vote, %s!\n", voterName);
                addVoter(voterName);
            }
            else
            {
                printf("\nInvalid vote submitted, please try again.\n");
                i--;
            }
        }

        if(i == votersCount)
        {
            printf("\nAll votes submitted!\n");
            printf("---------------------------------------\n");
            printf("Results:\n");
            printf("YES: %d\n", yesCount);
            printf("NO: %d\n", noCount);
        }
    }

    return 0;
}

int checkVoter(char name[])
{
    char filename[30];
    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE* fp = fopen(filename, "r");

    if(fp == NULL)
    {
        return 0;
    }
    else
    {
        fclose(fp);
        return 1;
    }
}

void addVoter(char name[])
{
    char filename[30];
    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE* fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("\nError in writing to file: %s\n", filename);
    }
    else
    {
        fprintf(fp, "Voting Complete - %s", name);
        fclose(fp);
    }
}