//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k;
    char bases[4] = {'A','C','G','T'}; //Array of possible bases
    char *genome = malloc(sizeof(char)*100000); //Allocate memory for genome sequence
    
    srand(time(NULL)); //Initialize random seed
    
    for(i=0;i<100000;i++) //Generate random genome sequence of length 100000
    {
        j = rand()%4; //Select a random base from the possible bases
        genome[i] = bases[j]; //Add the selected base to the genome sequence
    }
    
    printf("Genome sequence: \n");
    for(i=0;i<100000;i++)
    {
        printf("%c",genome[i]); //Print the generated genome sequence
    }
    printf("\n\n");
    
    printf("Inserting mutations... \n");
    for(i=0;i<100;i++) //Insert 100 random mutations
    {
        j = rand()%100000; //Select a random position in the genome sequence
        k = rand()%4; //Select a random base to change to
        printf("Mutation at position %d: %c -> %c \n",j,genome[j],bases[k]); //Print the mutation details
        genome[j] = bases[k]; //Insert the mutation in the genome sequence
    }
    
    printf("\nMutated genome sequence: \n");
    for(i=0;i<100000;i++)
    {
        printf("%c",genome[i]); //Print the mutated genome sequence
    }
    printf("\n");
    
    free(genome); //Free the allocated memory
    
    return 0; //End the program
}