//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10000
#define READ_LENGTH 100

char genome[GENOME_SIZE];

char random_nucleotide() {
  int r = rand() % 4;
  switch (r) {
    case 0: return 'A';
    case 1: return 'C';
    case 2: return 'G';
    case 3: return 'T';
  }
}

void randomize_genome() {
  srand(time(NULL));
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = random_nucleotide();
  }
}

void print_sequence(char* seq, int len, int id) {
  printf(">seq%d\n", id);
  for (int i = 0; i < len; i++) {
    printf("%c", seq[i]);
  }
  printf("\n");
}

void simulate_sequencing() {
  int num_reads = GENOME_SIZE / READ_LENGTH;
  char sequence[READ_LENGTH];
  int errors = 0, gaps = 0, duplicates = 0;
  for (int i = 0; i < num_reads; i++) {
    for (int j = 0; j < READ_LENGTH; j++) {
      int idx = i * READ_LENGTH + j;
      if (idx >= GENOME_SIZE) break;
      if (rand() % 10 == 0) { // introduce error with 10% probability
        char old_nucleotide = genome[idx];
        do {
          genome[idx] = random_nucleotide();
        } while (genome[idx] == old_nucleotide);
        errors++;
      }
      sequence[j] = genome[idx];
    }
    if (rand() % 10 == 0) { // introduce gaps with 10% probability
      int gap_size = rand() % 20 + 1;
      for (int j = READ_LENGTH-gap_size; j < READ_LENGTH; j++) {
        sequence[j] = '-';
      }
      gaps++;
    }
    if (rand() % 10 == 0) { // introduce duplication with 10% probability
      int dup_size = rand() % READ_LENGTH + 1;
      for (int k = 0; k < dup_size; k++) {
        print_sequence(sequence, READ_LENGTH, i);
        duplicates++;
      }
      i += dup_size / READ_LENGTH;
    } else {
      print_sequence(sequence, READ_LENGTH, i);
    }
  }
  printf("Sequencing errors: %d\n", errors);
  printf("Sequencing gaps: %d\n", gaps);
  printf("Sequencing duplicates: %d\n", duplicates);
}

int main() {
  randomize_genome();
  simulate_sequencing();
  return 0;
}