//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message to the simulator
  printf("Welcome to C Genome Sequencing Simulator\n\n");
  
  // Randomly generate a genome sequence of length 20
  srand(time(0));
  char genome[20];
  for(int i=0; i<20; i++) {
    int rand_num = rand()%4;
    if(rand_num == 0) genome[i] = 'A';
    else if(rand_num == 1) genome[i] = 'C';
    else if(rand_num == 2) genome[i] = 'G';
    else if(rand_num == 3) genome[i] = 'T';
  }
  
  // Print the randomly generated genome sequence
  printf("The randomly generated genome sequence is:\n%s\n\n", genome);
  
  // Prompt the user to enter a genome sequence for comparison
  printf("Please enter a genome sequence for comparison (length 20):\n");
  char user_genome[20];
  scanf("%s", user_genome);
  
  // Compare the user's genome sequence with the randomly generated sequence
  int matches = 0;
  for(int i=0; i<20; i++) {
    if(user_genome[i] == genome[i]) matches++;
  }
  
  // Print the number of matching bases and the similarity percentage
  float similarity = (float)matches/20 * 100;
  printf("Number of matching bases: %d\n", matches);
  printf("Similarity percentage: %.2f%%\n", similarity);
  
  return 0;
}