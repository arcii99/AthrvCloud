//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void generate_random_sequence(char *sequence, int length){
    const char *nucleotides = "ACGT";
    int i;
    for(i=0;i<length;i++){
        int random_number = rand() % 4;
        sequence[i] = nucleotides[random_number];
    }
    sequence[length]='\0';
    printf("Generated sequence: %s\n",sequence);
}

void simulate_mutations(char *sequence, float mutation_rate){
    int i, length=strlen(sequence);
    for(i=0;i<length;i++){
        float random_number = (float)rand()/(float)RAND_MAX;
        if(random_number <= mutation_rate){
            const char *nucleotides = "ACGT";
            int random_number = rand() % 4;
            sequence[i] = nucleotides[random_number];
        }
    }
    printf("Mutated sequence: %s\n",sequence);
}

int main(){
    char sequence[100];
    generate_random_sequence(sequence, 50);
    simulate_mutations(sequence, 0.10);
    return 0;
}