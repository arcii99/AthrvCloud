//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char dnaStrand[50];
    int strandLength, i;
    float gcPercentage;

    printf("Welcome to the DNA Analyzer 2000!\n");
    printf("Please enter your DNA Strand: ");
    scanf("%s", dnaStrand);
    strandLength = strlen(dnaStrand);

    int gcCount = 0;
    for(i = 0; i < strandLength; i++)
    {
        if(dnaStrand[i] == 'G' || dnaStrand[i] == 'C')
        {
            gcCount++;
        }
    }

    gcPercentage = ((float)gcCount/(float)strandLength) * 100.0;

    printf("\n\nAnalyzing... Please wait...\n\n");

    if(gcPercentage >= 50)
    {
        printf("Oh boy! Your DNA Strand is more than 50 percent G's and C's. Are you sure you're not a goat?\n");
    } else if(gcPercentage >= 25 && gcPercentage < 50)
    {
        printf("Hmmm... your DNA Strand is less than 50 percent G's and C's. Could you be a banana?\n");
    } else if(gcPercentage >= 10 && gcPercentage < 25)
    {
        printf("Interesting... your DNA Strand only has %f percent G's and C's. You could be a worm!\n", gcPercentage);
    } else {
        printf("This is a joke right? Your DNA Strand is less than 10 percent G's and C's. You're not even human!\n");
    }
    return 0;
}