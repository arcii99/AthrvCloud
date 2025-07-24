//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_SIZE 1000000

int main()
{
  char genome[GENOME_SIZE];
  int i, j, k;

  srand(time(NULL)); // Initialize random seed

  // Generate random genome sequence
  for(i=0; i<GENOME_SIZE; i++)
    genome[i] = rand()%4 + 'A'; // Randomly select A, C, G, T

  // Print the generated genome sequence
  printf("The generated genome sequence is:\n");
  for(i=0; i<GENOME_SIZE; i++)
  {
    printf("%c", genome[i]);
    if((i+1)%50 == 0) // Print 50 characters per line
      printf("\n");
  }

  // Find sub-sequence "ATCG" in genome
  int sub_seq_count = 0;
  for(i=0; i<GENOME_SIZE-3; i++)
  {
    if(genome[i] == 'A' && genome[i+1] == 'T' && genome[i+2] == 'C' && genome[i+3] == 'G')
      sub_seq_count++;
  }
  printf("\nNumber of sub-sequence 'ATCG' found in genome is: %d\n", sub_seq_count);

  // Find most common sub-sequence of length 10
  int max_count = 0;
  char max_count_seq[11];
  max_count_seq[10] = '\0';
  for(i=0; i<GENOME_SIZE-9; i++)
  {
    char sub_seq[11];
    sub_seq[10] = '\0';
    for(j=i; j<i+10; j++)
    {
      sub_seq[j-i] = genome[j];
    }
    int count = 0;
    for(j=0; j<GENOME_SIZE-9; j++)
    {
      int match = 1;
      for(k=0; k<10; k++)
      {
        if(genome[j+k] != sub_seq[k])
        {
          match = 0;
          break;
        }
      }
      if(match == 1)
        count++;
    }
    if(count > max_count)
    {
      max_count = count;
      for(j=0; j<10; j++)
        max_count_seq[j] = sub_seq[j];
    }
  }
  printf("\nMost common sub-sequence of length 10 is '%s', found %d times.\n", max_count_seq, max_count);

  return 0;
}