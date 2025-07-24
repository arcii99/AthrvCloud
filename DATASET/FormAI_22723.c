//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with system time
    
    int dnaSequenceLength = 100; // length of the DNA sequence
    char dnaSequence[dnaSequenceLength]; // array to hold the DNA sequence
    
    // randomly generate the DNA sequence
    for(int i = 0; i < dnaSequenceLength; i++)
    {
        int randomNum = rand() % 4; // generate a random number between 0 and 3
        
        if(randomNum == 0)
            dnaSequence[i] = 'A';
        else if(randomNum == 1)
            dnaSequence[i] = 'C';
        else if(randomNum == 2)
            dnaSequence[i] = 'G';
        else
            dnaSequence[i] = 'T';
    }
    
    // print the DNA sequence
    printf("The DNA sequence is: ");
    for(int i = 0; i < dnaSequenceLength; i++)
        printf("%c", dnaSequence[i]);
    printf("\n\n");
    
    // find and print all the occurrences of the specified DNA sequence pattern
    char dnaPattern[] = "ACG";
    int patternLength = strlen(dnaPattern);
    int patternFound = 0;
    
    for(int i = 0; i < dnaSequenceLength - patternLength + 1; i++)
    {
        int matchCount = 0;
        for(int j = 0; j < patternLength; j++)
        {
            if(dnaSequence[i+j] == dnaPattern[j])
                matchCount++;
        }
        if(matchCount == patternLength)
        {
            patternFound = 1;
            printf("Pattern found at index %d\n", i);
        }
    }
    if(patternFound == 0)
        printf("Pattern not found in the DNA sequence.\n");

    return 0;
}