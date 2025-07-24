//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 //Set the length of the genome
#define MUTATION_RATE 0.05 //Set the mutation rate for the genome
#define MAX_SEQUENCE 3 //Set the maximum sequence length to be detected

char get_random_base() {
    char bases[] = {'A', 'C', 'G', 'T'};
    int index = rand() % 4;
    return bases[index];
}

void generate_genome(char genome[]) {
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = get_random_base();
    }
    genome[GENOME_LENGTH] = '\0'; //Add null character to mark end of string
}

void mutate_genome(char genome[]) {
    for(int i=0; i<GENOME_LENGTH; i++) {
        float mutation_chance = (float) rand() / RAND_MAX;
        if(mutation_chance < MUTATION_RATE) {
            genome[i] = get_random_base();
        }
    }
}

void print_genome(char genome[]) {
    printf("%s\n", genome);
}

void detect_sequences(char genome[]) {
    int sequence_count[MAX_SEQUENCE] = {0}; //Initialize array to store count of sequences of each length
    for(int i=0; i<GENOME_LENGTH; i++) {
        for(int j=1; j<=MAX_SEQUENCE; j++) {
            if(i+j > GENOME_LENGTH) { //Check if remaining genome is too short for a sequence of length j
                break;
            }
            int is_sequence = 1;
            for(int k=1; k<j; k++) {
                if(genome[i] != genome[i+k]) {
                    is_sequence = 0;
                    break;
                }
            }
            if(is_sequence) {
                sequence_count[j-1]++; //Increment count of sequences of length j-1
            }
        }
    }
    printf("Sequences Found:\n");
    for(int i=0; i<MAX_SEQUENCE; i++) {
        printf("%d-length sequences: %d\n", i+1, sequence_count[i]);
    }
}

int main() {
    srand(time(0)); //Seed the random number generator with current time
    char genome[GENOME_LENGTH+1]; //Declare a char array to store the genome
    generate_genome(genome); //Generate a random genome
    printf("Initial Genome:\n");
    print_genome(genome); //Print the initial genome
    mutate_genome(genome); //Mutate the genome with probability MUTATION_RATE
    printf("Mutated Genome:\n");
    print_genome(genome); //Print the mutated genome
    detect_sequences(genome); //Detect and print count of sequences of length 1 to MAX_SEQUENCE
    return 0;
}