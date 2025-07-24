//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

char getRandomBase() {
    int randNum = rand() % 4;
    switch(randNum) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomBase();
    }
    printf("Randomly generated genome: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    return 0;
}