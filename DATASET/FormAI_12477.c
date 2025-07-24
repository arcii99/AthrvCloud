//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_SIZE 100

char* GenerateSequence() {
    char* sequence = malloc(sizeof(char) * SEQUENCE_SIZE);
    int i;
    for(i = 0; i < SEQUENCE_SIZE; i++) {
        int random = rand() % 4;
        switch(random) {
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
            default:
                break;
        }
    }
    return sequence;
}

void PrintSequence(char* sequence) {
    printf("%s\n", sequence);
}

int main() {
    srand(time(NULL));
    char* sequence = GenerateSequence();
    PrintSequence(sequence);
    free(sequence);
    return 0;
}