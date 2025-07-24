//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100

typedef struct {
  char genome[GENOME_LENGTH];
} organism;

void generateGenome(char* genome) {
  // random mutation generator
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    switch (rand() % 4) {
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
    }
  }
}

void printGenome(char* genome) {
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  organism org1, org2;
  generateGenome(org1.genome);
  generateGenome(org2.genome);

  printf("Organism 1: ");
  printGenome(org1.genome);
  printf("Organism 2: ");
  printGenome(org2.genome);

  // simulate gene sequencing
  char childGenome[GENOME_LENGTH];
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    int parent = rand() % 2;
    childGenome[i] = (parent == 0) ? org1.genome[i] : org2.genome[i];
  }

  printf("Child: ");
  printGenome(childGenome);

  return 0;
}