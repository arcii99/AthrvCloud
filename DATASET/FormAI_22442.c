//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char responses[10][50] = {"Yes, forsooth, it is meant to be.", "Nay, fair maiden, this is not your fate.", "The stars hath spoken, and they say yes.", "Tempt not the fates, for they say no.", "Methinks 'tis a promising endeavour.", "Beware, for the omens are not favourable.", "In a word, aye.", "Verily, nay.", "The answer shall reveal itself in time.", "Asketh me again, for my crystal ball needs polishing."};
    char question[50];
    int numResponses = 10, numQuestions = 0, responseIndex;
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller. What is your inquiry?\n");
    gets(question);
    while (strcmp(question, "quit") != 0)
    {
        responseIndex = rand() % numResponses;
        printf("\n%s\n", responses[responseIndex]);
        numQuestions += 1;
        if (numQuestions % 5 == 0)
        {
            printf("Might I interest thee in one of these fine mystical talismans?\n");
        }
        printf("\nWhat else dost thou seeketh to know?\n");
        gets(question);
    }
    printf("\nFare thee well, and may thy fortune be favourable.\n");
    return 0;
}