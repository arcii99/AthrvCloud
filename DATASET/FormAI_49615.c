//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01 // 1% mutation rate

char generate_base(){
    char base;
    int r = rand() % 4;
    switch(r){
        case 0:
            base = 'A';
            break;
        case 1:
            base = 'T';
            break;
        case 2:
            base = 'C';
            break;
        case 3:
            base = 'G';
            break;
        default:
            base = 'X';
            break;
    }
    return base;
}

void initialize_genome(char genome[GENOME_LENGTH]){
    for(int i=0; i<GENOME_LENGTH; i++){
        genome[i] = generate_base();
    }
}

void print_genome(char genome[GENOME_LENGTH]){
    for(int i=0; i<GENOME_LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutate_genome(char genome[GENOME_LENGTH]){
    for(int i=0; i<GENOME_LENGTH; i++){
        float r = (float) rand() / (float) RAND_MAX;
        if(r < MUTATION_RATE){
            genome[i] = generate_base();
        }
    }
}

int main(){

    srand(time(NULL));

    char genome[GENOME_LENGTH] = {0};

    initialize_genome(genome);
    printf("Initial genome:\n");
    print_genome(genome);

    mutate_genome(genome);
    printf("Mutated genome:\n");
    print_genome(genome);

    return 0;
}