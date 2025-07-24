//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to the Genome Sequencing Simulator!\n\n");
  printf("Please enter the length of the genome: ");
  
  int genome_length;
  scanf("%d", &genome_length);
  
  char genome[genome_length];
  
  // Generate random genome sequence
  srand(time(NULL));
  for(int i = 0; i < genome_length; i++){
    genome[i] = rand() % 4 + 'A';
  }
  
  // Print out the generated genome sequence
  printf("Generated genome sequence: \n");
  for(int i = 0; i < genome_length; i++){
    printf("%c", genome[i]);
  }
  
  // Simulate sequencing process
  int sequence_length = genome_length / 2;
  char sequence[sequence_length];
  
  printf("\n\nSequencing...\n");
  for(int i = 0; i < sequence_length; i++){
    int random_index = rand() % genome_length;
    sequence[i] = genome[random_index];
  }
  
  // Print out the sequenced genome fragment
  printf("\nSequenced genome fragment: \n");
  for(int i = 0; i < sequence_length; i++){
    printf("%c", sequence[i]);
  }
  
  printf("\n\nThank you for using the Genome Sequencing Simulator!");
  return 0;
}