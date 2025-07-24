//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printSequence(int* genome, int size){
    for(int i=0; i<size; i++){
        printf("%d ", genome[i]);
    }
    printf("\n");
}

void mutate(int* genome, int size, int rate){
    srand(time(0));
    for(int i=0; i<size; i++){
        int r = rand() % 100;
        if(r <= rate){
            genome[i] = rand() % 4;
        }
    }
}

int main(){
    int genomeSize = 10;
    int mutationRate = 10;

    int* genome = (int*) malloc(genomeSize * sizeof(int));
    if(genome == NULL){
        printf("Error: Unable to allocate memory\n");
        return 1;
    }

    // Initialize genome
    srand(time(0));
    for(int i=0; i<genomeSize; i++){
        genome[i] = rand() % 4;
    }

    printf("Starting genome sequence:\n");
    printSequence(genome, genomeSize);

    printf("\nMutated genome sequences:\n");
    for(int i=0; i<5; i++){
        mutate(genome, genomeSize, mutationRate);
        printSequence(genome, genomeSize);
    }

    free(genome);

    return 0;
}