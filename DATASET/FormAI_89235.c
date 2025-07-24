//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 100 //Length of genome sequence
#define MUTATION_RATE 0.05 //Mutation rate for each nucleotide

int main(){
    char genome[GENOME_LENGTH]; //Array to store genome sequence
    srand(time(NULL)); //Seed for random generator
    
    //Initializing genome sequence with random nucleotides
    for(int i=0; i<GENOME_LENGTH; i++){
        int r = rand() % 4; //Generate random number between 0 and 3
        switch(r){
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
    
    //Printing initial genome sequence
    printf("Initial genome sequence: ");
    for(int i=0; i<GENOME_LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
    
    //Simulating mutations in genome sequence
    for(int i=0; i<GENOME_LENGTH; i++){
        float r = (float)rand()/(float)RAND_MAX; //Generate random float between 0 and 1
        if(r < MUTATION_RATE){
            //Choose random nucleotide to mutate
            int r_nuc = rand() % 3;
            switch(r_nuc){
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
    
    //Printing mutated genome sequence
    printf("Mutated genome sequence: ");
    for(int i=0; i<GENOME_LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}