//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 1000

char genome[GENOME_SIZE]; //declare genome sequence

int main(){
    srand(time(NULL)); //seed random number generator
    
    //generate random genome sequence
    for(int i=0; i<GENOME_SIZE; i++){
        int nucleotide = rand()%4; //0=A, 1=C, 2=G, 3=T
        switch(nucleotide){
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
    
    //print genome sequence
    printf("Generated Genome Sequence:\n%s\n\n", genome);
    
    //search for motifs
    char motif[5] = "ACGT";
    int motif_count = 0;
    for(int i=0; i<GENOME_SIZE-4; i++){
        if(strncmp(motif, &genome[i], 4) == 0){
            motif_count++;
        }
    }
    
    //print motif count
    printf("Motif Count: %d\n\n", motif_count);
    
    return 0;
}