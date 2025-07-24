//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

char* generateGenome(int length){
    const char bases[] = {'A', 'C', 'G', 'T'};
    char* genome = (char*)malloc((length+1)*sizeof(char));
    for(int i=0; i<length; i++){
        genome[i] = bases[rand()%4]; //choose randomly from four bases
    }
    genome[length] = '\0';
    return genome;
}

int main(){
    int genomeLength;
    printf("Enter the length of genome: ");
    scanf("%d", &genomeLength);
    
    char* genome = generateGenome(genomeLength);
    printf("Generated Genome: %s\n", genome);
    
    int nMutations;
    printf("Enter the number of mutations: ");
    scanf("%d", &nMutations);
    
    for(int i=0; i<nMutations; i++){
        int mutationIndex = rand()%genomeLength;
        char newBase;
        do{
            newBase = "ACGT"[rand()%4]; //choose a new base
        }while(newBase == genome[mutationIndex]); //make sure the new base is different
        genome[mutationIndex] = newBase;
    }
    
    printf("Mutated Genome: %s\n", genome);
    
    return 0;
}