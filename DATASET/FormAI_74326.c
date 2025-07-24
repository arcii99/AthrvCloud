//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 1000

char generate_nucleotide() {
  int random_number = rand() % 4;
  if (random_number == 0) {
    return 'A';
  } else if (random_number == 1) {
    return 'C';
  } else if (random_number == 2) {
    return 'G';
  } else {
    return 'T';
  }
}

void generate_genome(char genome[DNA_LENGTH]) {
  for (int i=0; i<DNA_LENGTH; i++) {
    genome[i] = generate_nucleotide();
  }
}

void print_genome(char genome[DNA_LENGTH]) {
  for (int i=0; i<DNA_LENGTH; i++) {
    printf("%c", genome[i]);
  }
}

int count_occurrences(char genome[DNA_LENGTH], char target_nucleotide) {
  int count = 0;
  for (int i=0; i<DNA_LENGTH; i++) {
    if (genome[i] == target_nucleotide) {
      count++;
    }
  }
  return count;
}

int main() {
  srand(time(NULL));
  char genome[DNA_LENGTH];
  generate_genome(genome);
  printf("Generated genome:\n");
  print_genome(genome);
  printf("\n\n");
  printf("Occurrences of each nucleotide:\n");
  printf("A: %d\n", count_occurrences(genome, 'A'));
  printf("C: %d\n", count_occurrences(genome, 'C'));
  printf("G: %d\n", count_occurrences(genome, 'G'));
  printf("T: %d\n", count_occurrences(genome, 'T'));
  return 0;
}