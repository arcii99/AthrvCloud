//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_SIZE 100 //Size of the genome sequence
#define BASE_PAIRS 4 //Number of base pairs in DNA

//Function to generate random base pair
char generate_base_pair(){
    int random_num = rand() % BASE_PAIRS;
    switch(random_num){
        case 0:
            return 'A';
        case 1:
            return 'T';
        case 2:
            return 'C';
        case 3:
            return 'G';
    }
}

//Function to generate random genome sequence
void generate_genome_sequence(char genome[]){
    int i;
    for(i=0; i<GENOME_SIZE; i++){
        genome[i] = generate_base_pair();
    }
}

//Function to print the genome sequence
void print_genome_sequence(char genome[]){
    int i;
    for(i=0; i<GENOME_SIZE; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main(){
    srand(time(0)); //Setting seed for rand() function
    char genome[GENOME_SIZE];
    generate_genome_sequence(genome);
    printf("The generated genome sequence is:\n");
    print_genome_sequence(genome);
    return 0;
}