//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_SIZE 1000000

char* generate_sequence() {
    char *sequence = (char*)malloc(sizeof(char) * GENOME_SIZE);

    srand(time(0));

    for(int i = 0; i < GENOME_SIZE; i++) {
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
        }
    }

    return sequence;
}

void display_sequence(char *sequence) {
    printf("%s", sequence);
}

int main() {
    char* sequence = generate_sequence();

    printf("Genome sequence generated:\n");
    display_sequence(sequence);

    free(sequence);

    return 0;
}