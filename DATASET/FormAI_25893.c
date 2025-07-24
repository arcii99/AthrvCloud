//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10

char randomBase(){
  char bases[] = {'A', 'C', 'G', 'T'};
  return bases[rand() % 4];
}

void randomGenome(char genome[]){
  for(int i = 0; i < GENOME_SIZE; i++){
    genome[i] = randomBase();
  }
  genome[GENOME_SIZE] = '\0';
}

int main(){
  srand(time(NULL));

  char genome1[GENOME_SIZE + 1];
  char genome2[GENOME_SIZE + 1];

  printf("Generating two random genomes...\n");
  randomGenome(genome1);
  randomGenome(genome2);

  printf("Genome 1: %s\n", genome1);
  printf("Genome 2: %s\n", genome2);

  printf("Performing genome sequencing...\n");

  int matches = 0;
  for(int i = 0; i < GENOME_SIZE; i++){
    if(genome1[i] == genome2[i]){
      matches++;
    }
  }

  printf("Sequence match percentage: %d%%\n", (int)(((float)matches / GENOME_SIZE) * 100));

  return 0;
}