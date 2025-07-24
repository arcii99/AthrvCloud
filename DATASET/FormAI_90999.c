//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 100 /* Size of the genome */
#define READ_LENGTH 10 /* Size of the reads */
#define ERROR_RATE 0.05 /* Probability of error in a read */

char random_base() {
    char bases[4] = {'A', 'C', 'G', 'T'};
    return bases[rand() % 4];
}

void generate_genome(char *genome) {
    int i;
    for(i = 0; i < GENOME_SIZE; i++) {
        genome[i] = random_base();
    }
}

void generate_reads(char *genome, char *reads) {
    int i, j;
    for(i = 0; i < GENOME_SIZE - READ_LENGTH; i++) {
        for(j = 0; j < READ_LENGTH; j++) {
            char base = genome[i + j];
            if((double) rand() / RAND_MAX < ERROR_RATE) {
                do {
                    base = random_base();
                } while(base == genome[i + j]);
            }
            reads[i * READ_LENGTH + j] = base;
        }
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_SIZE + 1], reads[GENOME_SIZE * READ_LENGTH + 1];
    generate_genome(genome);
    generate_reads(genome, reads);
    genome[GENOME_SIZE] = '\0';
    reads[GENOME_SIZE * READ_LENGTH] = '\0';
    printf("Genome: %s\n", genome);
    printf("Reads:\n%s\n", reads);
    return 0;
}