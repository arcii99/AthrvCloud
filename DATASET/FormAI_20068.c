//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

void generate_genome(char genome[]);
void print_genome(char genome[]);
void mutate_genome(char genome[]);
int match_genome(char genome1[], char genome2[]);

int main() {
  srand(time(NULL));
  char genome1[GENOME_LENGTH], genome2[GENOME_LENGTH];
  int i, matches;
  
  // Generate two genomes
  generate_genome(genome1);
  generate_genome(genome2);
  
  printf("Initial genomes:\n");
  printf("Genome 1: ");
  print_genome(genome1);
  printf("Genome 2: ");
  print_genome(genome2);
  
  // Allow for up to 100 mutations
  for (i = 0; i < 100; i++) {
    // Randomly mutate one of the genomes
    mutate_genome(genome1);
    
    // Check for a match
    matches = match_genome(genome1, genome2);
    if (matches > 0) {
      printf("Match found after %d mutations!\n", i+1);
      printf("Genome 1: ");
      print_genome(genome1);
      printf("Genome 2: ");
      print_genome(genome2);
      return 0;
    }
  }
  
  printf("No match found after 100 mutations.\n");
  printf("Genome 1: ");
  print_genome(genome1);
  printf("Genome 2: ");
  print_genome(genome2);
  
  return 0;
}

// Generate a random genome
void generate_genome(char genome[]) {
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = rand() % 4;
  }
}

// Print the genome as a sequence of letters
void print_genome(char genome[]) {
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    switch (genome[i]) {
      case 0:
        printf("A");
        break;
      case 1:
        printf("C");
        break;
      case 2:
        printf("G");
        break;
      case 3:
        printf("T");
        break;
    }
  }
  printf("\n");
}

// Mutate a random location in the genome
void mutate_genome(char genome[]) {
  int location = rand() % GENOME_LENGTH;
  genome[location] = rand() % 4;
}

// Count the number of matching positions
int match_genome(char genome1[], char genome2[]) {
  int i, matches = 0;
  for (i = 0; i < GENOME_LENGTH; i++) {
    if (genome1[i] == genome2[i]) {
      matches++;
    }
  }
  return matches;
}