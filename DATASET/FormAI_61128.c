//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_LEN 100  // Maximum length of random DNA sequence to be generated

// Function to generate random DNA sequence of given length
char* randomSequence(int len){
    char dna[5] = {'A', 'T', 'C', 'G'};
    char* seq = malloc(len + 1);

    for(int i=0; i<len; i++){
        int randIndex = rand() % 4;
        seq[i] = dna[randIndex];
    }
    seq[len] = '\0';
    return seq;
}

// Function to simulate genome sequencing
void genomeSequencing(char* genome, int genomeLen, int readLen){
    printf("Genome: %s\n", genome);
    printf("Genome length: %d\n", genomeLen);
    printf("Read length: %d\n\n", readLen);

    int numReads = genomeLen / readLen;
    printf("Number of reads: %d\n", numReads);

    for(int i=0; i<numReads; i++){
        char* read = malloc(readLen + 1);
        strncpy(read, genome+(i*readLen), readLen);
        read[readLen] = '\0';
        printf("Read %d: %s\n", i+1, read);
        free(read);
    }

    if(genomeLen % readLen != 0){
        char* read = malloc(readLen + 1);
        strncpy(read, genome+(numReads*readLen), genomeLen%readLen);
        read[genomeLen%readLen] = '\0';
        printf("Read %d: %s\n", numReads+1, read);
        free(read);
    }
}

int main(){
    srand(time(NULL));  // Seed for random number generator

    int genomeLen;
    int readLen;

    printf("Enter the length of genome: ");
    scanf("%d", &genomeLen);

    printf("Enter the length of read: ");
    scanf("%d", &readLen);

    char* genome = randomSequence(genomeLen);

    genomeSequencing(genome, genomeLen, readLen);

    free(genome);
    return 0;
}