//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));              // seed random number generator with time
    int nucleotides[4] = {0};       // array to store count of each nucleotide
    
    // create random DNA sequence of length 50
    char dna[50];
    for (int i = 0; i < 50; i++) {
        int random_num = rand() % 4;        // generate random number 0-3
        switch(random_num) {
            case 0: dna[i] = 'A'; nucleotides[0]++; break;
            case 1: dna[i] = 'C'; nucleotides[1]++; break;
            case 2: dna[i] = 'G'; nucleotides[2]++; break;
            case 3: dna[i] = 'T'; nucleotides[3]++; break;
        }
    }
    
    // print nucleotide counts and DNA sequence
    printf("Nucleotide counts:\nA: %d\nC: %d\nG: %d\nT: %d\n\n", nucleotides[0], nucleotides[1], nucleotides[2], nucleotides[3]);
    printf("DNA sequence:\n%s\n\n", dna);
    
    // create mutated DNA sequence
    char mutated_dna[50];
    for (int i = 0; i < 50; i++) {
        mutated_dna[i] = dna[i];        // copy original sequence to start
        int mutation_chance = rand() % 10;       // 10% chance of mutation
        if (mutation_chance == 0) {
            int random_num = rand() % 2;    // generate random number 0 or 1
            switch(random_num) {
                case 0: mutated_dna[i] = 'A'; nucleotides[0]++; break;
                case 1: mutated_dna[i] = 'C'; nucleotides[1]++; break;
            }
        } else if (mutation_chance == 1) {
            int random_num = rand() % 2;
            switch(random_num) {
                case 0: mutated_dna[i] = 'G'; nucleotides[2]++; break;
                case 1: mutated_dna[i] = 'T'; nucleotides[3]++; break;
            }
        }
    }
    
    // print nucleotide counts and mutated DNA sequence
    printf("Mutated nucleotide counts:\nA: %d\nC: %d\nG: %d\nT: %d\n\n", nucleotides[0], nucleotides[1], nucleotides[2], nucleotides[3]);
    printf("Mutated DNA sequence:\n%s\n", mutated_dna);
    
    return 0;
}