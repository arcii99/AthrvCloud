//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_BASES 1000
#define MAX_BASES 5000

typedef enum { A, C, G, T } Base;

void generate_sequence(Base *seq, int bases);
void print_sequence(Base *seq, int bases);

int main(void) {
    int bases = rand() % (MAX_BASES - MIN_BASES + 1) + MIN_BASES;
    Base *seq = malloc(bases * sizeof(Base));
    srand(time(NULL));
    generate_sequence(seq, bases);
    print_sequence(seq, bases);
    free(seq);
    return 0;
}

void generate_sequence(Base *seq, int bases) {
    int i;
    for (i = 0; i < bases; i++) {
        seq[i] = rand() % 4;
    }
}

void print_sequence(Base *seq, int bases) {
    int i;
    for (i = 0; i < bases; i++) {
      switch (seq[i]) {
          case A: printf("A"); break;
          case C: printf("C"); break;
          case G: printf("G"); break;
          case T: printf("T"); break;
        }
    }
    printf("\n");
}