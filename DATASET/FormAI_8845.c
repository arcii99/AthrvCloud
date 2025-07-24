//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    //create an array representing the source genome
    char sourceGenome[1000];
    //create an array representing the sequenced genome
    char sequencedGenome[1000];
    //create random alphabet characters to fill the source genome
    char alphabet[4] = { 'A', 'C', 'T', 'G' };

    //initialize the random number generator
    srand(time(NULL));

    //fill the source genome with random alphabet characters
    for(int i = 0; i < 1000; i++){
        int index = rand() % 4;
        sourceGenome[i] = alphabet[index];
    }

    //simulate the sequencing process by copying the source genome and introducing mutations
    for(int i = 0; i < 1000; i++){
        //copy the current base from the source genome
        sequencedGenome[i] = sourceGenome[i];

        //introduce a mutation with a probability of 1 in 100
        if(rand() % 100 == 0){
            //generate a new random base by selecting from the remaining bases
            char newBase = alphabet[rand() % 3];
            //replace the current base with the new base
            sequencedGenome[i] = newBase;
        }
    }

    //print the source genome and the sequenced genome
    printf("Source Genome: %s\n", sourceGenome);
    printf("Sequenced Genome: %s\n", sequencedGenome);

    return 0;
}