//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char basePair() {
  char basePairs[] = "ATCG";
  int randomNum = rand() % 4;
  return basePairs[randomNum];
}

void generateGenome(char* genome, int length) {
  for (int i = 0; i < length; i++) {
    genome[i] = basePair();
  }
}

void printNucleotides(char* genome, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c ", genome[i]);
  }
  printf("\n");
}

void storeToFile(char* genome, int length) {
  FILE* fp;
  fp = fopen("genome_sequence.txt", "w");
  fprintf(fp, "%s", genome);
  fclose(fp);
}

int main() {
  srand(time(0));
  
  int genomeLength = 10000;
  char genome[genomeLength];
  
  printf("Generating genome sequence..\n");
  generateGenome(genome, genomeLength);
  printf("Genome sequence generated.\n");

  printf("Printing nucleotides..\n");
  printNucleotides(genome, genomeLength);
  printf("Nucleotides printed.\n");

  printf("Storing genome sequence to file..\n");
  storeToFile(genome, genomeLength);
  printf("Genome sequence stored.\n");

  return 0;
}