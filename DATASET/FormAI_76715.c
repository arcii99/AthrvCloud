//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Genome Sequencing Simulator!\n");

    srand(time(0));

    char genome[1000000];
    int i;

    for (i = 0; i < 1000000; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
            default:
                printf("Something went wrong!\n");
                return 1;
        }
    }

    printf("Genome generation complete!\n");

    FILE *sequence_file;
    sequence_file = fopen("genome_sequence.txt", "w");

    if (!sequence_file) {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    printf("Writing genome sequence to file...\n");

    for (i = 0; i < 1000000; i++) {
        fprintf(sequence_file, "%c", genome[i]);
    }

    fclose(sequence_file);

    printf("Sequencing complete! Check genome_sequence.txt for results.\n");

    return 0;
}