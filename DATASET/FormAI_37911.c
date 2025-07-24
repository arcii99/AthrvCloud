//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ACID_LENGTH 100

void displayHeader(int numBases, int numSequences) {
    printf("----------------------------------------------------------\n");  
    printf("\tWelcome to the Genome Sequencing Simulator\n");
    printf("----------------------------------------------------------\n\n");
    printf("Total bases in the DNA sequence : %d\n", numBases);
    printf("Total number of sequences to be generated : %d\n\n", numSequences);
}

void generateSequences(int numBases, int numSequences) {
    int i, j;
    char bases[4] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    for(i=1; i<=numSequences; i++) {
        printf("Sequence %d : ", i);
        for(j=0; j<numBases; j++) {
            printf("%c", bases[rand()%4]);
        }
        printf("\n");
    }
}

int main() {
    int numBases, numSequences;
    printf("Enter the total number of bases in the DNA sequence : ");
    scanf("%d", &numBases);
    printf("\nEnter the total number of sequences to generate : ");
    scanf("%d", &numSequences);
    displayHeader(numBases, numSequences);
    generateSequences(numBases, numSequences);
    return 0;
}