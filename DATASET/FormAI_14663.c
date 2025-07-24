//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 50 //length of genome sequence

int main(){
    //initialize variables
    char genome[LENGTH];
    srand(time(NULL)); //seed the random number generator 

    //generate random genome sequence
    for(int i = 0; i < LENGTH; i++){
        int random_num = rand() % 4; //generate random number from 0-3
        if(random_num == 0)
            genome[i] = 'A';
        else if(random_num == 1)
            genome[i] = 'C';
        else if(random_num == 2)
            genome[i] = 'G';
        else
            genome[i] = 'T';   
    }
    
    //print genome sequence
    printf("Genome Sequence: ");
    for(int i = 0; i < LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    //simulate errors in genome sequence
    int num_errors = rand() % 5; //generate random number of errors
    for(int i = 0; i < num_errors; i++){
        int random_index = rand() % LENGTH; //generate random index
        int random_num = rand() % 4; //generate random number from 0-3
        if(random_num == 0)
            genome[random_index] = 'A';
        else if(random_num == 1)
            genome[random_index] = 'C';
        else if(random_num == 2)
            genome[random_index] = 'G';
        else
            genome[random_index] = 'T';   
    }
    
    //print mutated genome sequence
    printf("Mutated Genome Sequence: ");
    for(int i = 0; i < LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}