//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //seed the random number generator
    
    printf("Welcome to the Zombie DNA Sequencer 3000!\n");
    printf("Please enter your DNA sequence: ");

    char dna[50];
    scanf("%s", dna);

    printf("Working...");

    // randomly mutate the DNA sequence
    for (int i = 0; i < 50; i++) {
        int rand_num = rand() % 5;

        if (rand_num == 0) {
            dna[i] = 'A';
        } else if (rand_num == 1) {
            dna[i] = 'T';
        } else if (rand_num == 2) {
            dna[i] = 'G';
        } else if (rand_num == 3) {
            dna[i] = 'C';
        } else {
            dna[i] = '-'; //uh oh, mutation caused a deletion
        }
    }

    // print out the mutated DNA sequence
    printf("\nMutated DNA sequence: %s\n", dna);

    // check for zombie virus
    if (dna[0] == 'G' && dna[1] == 'G' && dna[2] == 'T' && dna[3] == 'G' && dna[4] == 'T' && dna[5] == 'A') {
        printf("Zombie virus detected! Seek immediate medical attention.\n");
    } else {
        printf("No zombie virus detected. You're safe... for now.\n");
    }

    return 0;
}