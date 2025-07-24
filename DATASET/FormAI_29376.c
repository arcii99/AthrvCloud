//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SEQ_SIZE 10000
#define DIFF_THRESHOLD 50
#define MUTATION_PROBABILITY 0.001

typedef struct {
    char sequence[SEQ_SIZE];
    int size;
} Genome;

int compare(Genome g1, Genome g2) {
    int differences = 0;
    for(int i=0; i<g1.size; i++) {
        if(g1.sequence[i] != g2.sequence[i]) {
            differences++;
        }
    }
    return differences;
}

void mutate(Genome *g) {
    for(int i=0; i<g->size; i++) {
        if(rand()/(double)RAND_MAX < MUTATION_PROBABILITY) {
            g->sequence[i] = (char) (rand()%4 + 'A');
        }
    }
}

int main() {
    srand(time(0));
    Genome original, mutated;
    // generate original sequence
    for(int i=0; i<SEQ_SIZE; i++) {
        original.sequence[i] = (char) (rand()%4 + 'A');
    }
    original.size = SEQ_SIZE;
    // simulate mutations
    memcpy(&mutated, &original, sizeof(Genome));
    mutate(&mutated);
    // find differences
    int differences = compare(original, mutated);
    if(differences < DIFF_THRESHOLD) {
        printf("Mutated sequence is similar enough to original");
    } else {
        printf("Mutated sequence is different enough from original");
    }
    return 0;
}