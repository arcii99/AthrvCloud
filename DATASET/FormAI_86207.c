//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>

int main()
{
    printf("What?! A Genome Sequencing Simulator?\n");
    printf("This is unreal. I never thought I would be involved in creating such a thing!\n");
    printf("But here goes nothing.\n");
    
    int genomeLength = 100;
    int genome[genomeLength];
    
    printf("\nFirst, let's create a random genome sequence.\n");
    for (int i = 0; i < genomeLength; i++) {
        genome[i] = rand() % 4; //Randomly select one of four nucleotides (0-3)
    }
    
    printf("Generated Genome: ");
    for (int i = 0; i < genomeLength; i++) {
        printf("%d", genome[i]);
    }
    printf("\n");
    
    printf("\nNow, we need to create a sequencing simulator that uses this genome as a reference.\n");
    printf("Let's pretend we have a sequencer that can read up to 5 nucleotides at a time.\n");
    
    int start = 0;
    int readLength = 5;
    
    printf("\nSimulating Sequencing...\n");
    while (start < genomeLength) {
        printf("Reading Genome from Position %d to %d: ", start, start + readLength - 1);
        for (int i = 0; i < readLength; i++) {
            if (start + i < genomeLength) {
                printf("%d", genome[start + i]);
            }
        }
        printf("\n");
        start += readLength;
    }
    
    printf("\nWow, that was intense! But we did it.\n");
    
    return 0;
}