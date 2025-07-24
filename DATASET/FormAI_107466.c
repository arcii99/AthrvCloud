//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include<stdlib.h>
#include<stdio.h>

//Defining the nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

int main(){
    int genome_length = 1000000;
    char * sequence = (char *) malloc(sizeof(char)*genome_length);

    //Initialize random seed
    srand(time(NULL));

    //Creating the simulated genome sequence
    for(int i=0; i<genome_length; i++){
        int random = rand()%4;
        switch(random) {
            case 0:
                sequence[i] = A;
                break;
            case 1:
                sequence[i] = C;
                break;
            case 2:
                sequence[i] = G;
                break;
            case 3:
                sequence[i] = T;
                break;
        }
    }

    //Printing the genome sequence
    printf("The generated genome sequence is:\n");
    for(int i=0; i<genome_length; i++){
        if(i%70==0 && i!=0) printf("\n");
        printf("%c", sequence[i]);
    }
    printf("\n");

    free(sequence);
    return 0;
}