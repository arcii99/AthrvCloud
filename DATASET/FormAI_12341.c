//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 5

void generateGenome(char *genome){
    int i;
    for(i = 0; i < GENOME_LENGTH; i++){
        int randNum = rand() % 4; // Generates a random number between 0 and 3
        switch(randNum){
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
}

void mutateGenome(char *genome){
    int i;
    for(i = 0; i < GENOME_LENGTH; i++){
        int randNum = rand() % 100; // Generates a random number between 0 and 99
        if(randNum < MUTATION_RATE){
            randNum = rand() % 3; // Generates a random number between 0 and 2
            switch(randNum){
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'C';
                    break;
                case 2:
                    genome[i] = 'G';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
            }
        }
    }
}

void printGenome(char *genome){
    int i;
    for(i = 0; i < GENOME_LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL)); // For random number generation

    char originalGenome[GENOME_LENGTH];
    generateGenome(originalGenome);

    printf("Original Genome: ");
    printGenome(originalGenome);
    printf("\n");

    char mutatedGenome[GENOME_LENGTH];
    int i;
    for(i = 0; i < 3; i++){
        printf("Mutation #%d: ", i+1);
        generateGenome(mutatedGenome);
        mutateGenome(mutatedGenome);
        printGenome(mutatedGenome);
        printf("\n");
    }

    return 0;
}