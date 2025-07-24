//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000

char nucleotides[] = "ACTG";

char randomNucleotide() {
    // Returns a random nucleotide from the nucleotides string
    int randomIndex = rand() % 4;
    return nucleotides[randomIndex];
}

void printGenome(char genome[]) {
    // Prints out the genome in groups of 10 nucleotides per line
    int i;
    for (i = 0; genome[i] != '\0'; i++) {
        printf("%c ", genome[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Initialize genome with null characters
    char genome[MAX_GENOME_LENGTH] = {'\0'};

    int genomeLength;
    printf("Enter the length of the genome: ");
    scanf("%d", &genomeLength);

    // Generate random nucleotides for each position in genome
    int i;
    for (i = 0; i < genomeLength; i++) {
        genome[i] = randomNucleotide();
    }

    printf("\n\n");
    printGenome(genome);

    return 0;
}