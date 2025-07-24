//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.005
#define NUM_READS 10
#define READ_LENGTH 10
#define ERR_RATE 0.02

char getRandomBase() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        default:
            return 'T';
    }
}

void mutate(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = getRandomBase();
        }
    }
}

char* createGenome() {
    char* genome = malloc(GENOME_LENGTH * sizeof(char));
    if (genome == NULL) {
        perror("Error allocating memory for genome");
        exit(1);
    }
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomBase();
    }
    return genome;
}

void printGenome(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

char* generateReads(char* genome) {
    char* reads = malloc(NUM_READS * READ_LENGTH * sizeof(char));
    if (reads == NULL) {
        perror("Error allocating memory for reads");
        exit(1);
    }
    for (int i = 0; i < NUM_READS; i++) {
        int start = rand() % (GENOME_LENGTH - READ_LENGTH + 1);
        for (int j = 0; j < READ_LENGTH; j++) {
            char base = genome[start + j];
            if ((double)rand() / RAND_MAX < ERR_RATE) {
                switch (base) {
                    case 'A':
                        base = 'C';
                        break;
                    case 'C':
                        base = 'G';
                        break;
                    case 'G':
                        base = 'T';
                        break;
                    case 'T':
                        base = 'A';
                        break;
                }
            }
            reads[i * READ_LENGTH + j] = base;
        }
    }
    return reads;
}

void printReads(char* reads) {
    for (int i = 0; i < NUM_READS; i++) {
        for (int j = 0; j < READ_LENGTH; j++) {
            printf("%c", reads[i * READ_LENGTH + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char* genome = createGenome();
    printf("Original genome:\n");
    printGenome(genome);
    mutate(genome);
    printf("Mutated genome:\n");
    printGenome(genome);
    char* reads = generateReads(genome);
    printf("Generated reads:\n");
    printReads(reads);
    free(genome);
    free(reads);
    return 0;
}