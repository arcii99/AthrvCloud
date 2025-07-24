//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int genome_length, error_rate;
  printf("Enter the length of genome sequence: ");
  scanf("%d", &genome_length);
  printf("Enter the error rate (in percentage): ");
  scanf("%d", &error_rate);

  char nucleotides[] = {'A', 'T', 'C', 'G'};
  int error_cutoff = (float) genome_length * ((float) error_rate / 100);
  srand(time(NULL));
  int error_count = 0;

  printf("Generating genome sequence...\n");
  for (int i = 0; i < genome_length; i++){
    int error_check = rand() % 100 + 1;
    if (error_check <= error_rate && error_count < error_cutoff){
      printf("%c", nucleotides[rand() % 4]);
      error_count++;
    } else {
      printf("%c", nucleotides[rand() % 3]);
    }
  }

  printf("\nFinished genome sequence with %d errors out of %d nucleotides\n", error_count, genome_length);

  return 0;
}