//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    char nucleotides[] = {'A', 'C', 'T', 'G'};

    int length = rand() % 1000 + 500; // generate a random length between 500 and 1500

    char* genome = (char*) malloc(length * sizeof(char)); // allocate memory for the genome

    for (int i = 0; i < length; i++) { // generate random nucleotides and store them in the genome
        int index = rand() % 4;
        genome[i] = nucleotides[index];
    }

    printf("Genome Sequence: ");
    for (int i = 0; i < length; i++) { // print the genome sequence
        printf("%c", genome[i]);
    }

    free(genome); // free the memory allocated for the genome

    return 0;
}