//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long int genome_size, i;
    char nucleotides[] = "ATCG";
    srand(time(NULL));

    printf("Enter genome size: ");
    scanf("%ld", &genome_size);

    char *genome_sequence = (char*)malloc(sizeof(char) * genome_size);

    if(genome_sequence == NULL) {
        printf("Error: Memory allocation failed!");
        return 1;
    }

    printf("Generating genome sequence...\n");

    for(i = 0; i < genome_size; i++) {
        genome_sequence[i] = nucleotides[rand() % 4];
        printf("%c", genome_sequence[i]);
    }
    printf("\n");

    free(genome_sequence);
    printf("Genome sequence memory freed.\n");

    return 0;
}