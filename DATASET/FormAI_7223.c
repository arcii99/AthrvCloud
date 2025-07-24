//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 10000

char* generate_sequence() {
    char* sequence = malloc(SEQUENCE_LENGTH * sizeof(char));
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
            break;
        }
    }
    return sequence;
}

int main() {
    srand(time(NULL));
    char* sequence = generate_sequence();
    printf("Generated Sequence: %s\n", sequence);
    free(sequence);
    return 0;
}