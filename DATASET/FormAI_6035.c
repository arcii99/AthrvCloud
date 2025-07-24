//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>

#define GENOME_SIZE 100

void printGenome(char genome[]){
    for(int i = 0; i < GENOME_SIZE; i++){
        printf("%c", genome[i]);
        if((i+1) % 10 == 0) printf(" ");
        if((i+1) % 50 == 0) printf("\n");
    }
}

void generateRandomGenome(char genome[]){
    for(int i = 0; i < GENOME_SIZE; i++){
        int randomNum = rand() % 4;
        switch(randomNum){
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'C';
                break;
        }
    }
}

int main(){
    char genome[GENOME_SIZE];
    generateRandomGenome(genome);
    printf("Randomly generated genome:\n");
    printGenome(genome);
    return 0;
}