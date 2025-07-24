//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Define a function that generates random nucleotides
char random_nucleotide(){
    char nucleotides[] = {'A', 'T', 'C', 'G'};
    int rand_index = rand() % 4;
    return nucleotides[rand_index];
}

//Define a function that generates a random DNA sequence of a given length
char* random_DNA_sequence(int length){
    char* sequence = (char*) malloc((length+1)*sizeof(char));
    for(int i=0; i<length; i++){
        sequence[i] = random_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

//Define a function to mutate the DNA sequence
void mutate_sequence(char* sequence, int num_mutations){
    int length = strlen(sequence);
    for(int i=0; i<num_mutations; i++){
        int rand_index = rand() % length;
        char new_nucleotide = random_nucleotide();
        while(new_nucleotide == sequence[rand_index]){
            new_nucleotide = random_nucleotide();
        }
        sequence[rand_index] = new_nucleotide;
    }
}

//Define the main function
int main(){
    //Seed the random number generator with the current time
    srand(time(NULL));
    //Generate a random DNA sequence of length 10
    char* initial_sequence = random_DNA_sequence(10);
    printf("Initial sequence: %s\n", initial_sequence);
    //Mutate the sequence with 3 random mutations
    mutate_sequence(initial_sequence, 3);
    printf("Mutated sequence: %s\n", initial_sequence);
    //Free the memory allocated for the sequence
    free(initial_sequence);
    return 0;
}