//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

int main()
{
    int genome[GENOME_LENGTH];
    srand(time(NULL));
    
    // Generate random genome sequence
    for(int i=0;i<GENOME_LENGTH;i++){
        genome[i] = rand() % 4; // 0=A, 1=C, 2=G, 3=T
    }
    
    // Print original genome sequence
    printf("Original Genome Sequence:\n");
    for(int i=0;i<GENOME_LENGTH;i++){
        switch(genome[i]){
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("N");
                break;
        }
    }
    printf("\n");
    
    // Simulate Errors
    int num_errors = GENOME_LENGTH/20; // introduce 5% errors
    for(int i=0;i<num_errors;i++){
        int pos = rand()%GENOME_LENGTH; // pick random position
        int new_base = rand()%4; // pick random base
        while(new_base == genome[pos]) new_base = rand()%4; // ensure new base is different
        genome[pos] = new_base; // introduce error
    }
    
    // Print mutated genome sequence
    printf("Mutated Genome Sequence:\n");
    for(int i=0;i<GENOME_LENGTH;i++){
        switch(genome[i]){
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("N");
                break;
        }
    }
    printf("\n");
    
    return 0;
}