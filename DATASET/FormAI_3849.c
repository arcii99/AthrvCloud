//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator with current time

  // define a genome sequence of length 100
  char genome[100];
  
  // generate random base pairs for the genome sequence
  for(int i = 0; i < 100; i++) {
    int random_num = rand() % 4; // generate a random number between 0 and 3
  
    switch(random_num) {
      case 0:
        genome[i] = 'A';
        break;
      case 1:
        genome[i] = 'C';
        break;
      case 2:
        genome[i] = 'G';
        break;
      case 3:
        genome[i] = 'T';
        break;
    }
  }
  
  // print the generated genome sequence
  printf("Generated genome sequence: ");
  for(int i = 0; i < 100; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");
  
  // simulate a mutation event
  int random_index = rand() % 100; // generate a random index between 0 and 99
  int random_num = rand() % 3; // generate a random number between 0 and 2
  
  // mutate the genome sequence at the randomly selected index
  switch(random_num) {
    case 0:
      genome[random_index] = 'A';
      break;
    case 1:
      genome[random_index] = 'C';
      break;
    case 2:
      genome[random_index] = 'G';
      break;
    case 3:
      genome[random_index] = 'T';
      break;
  }
  
  // print the mutated genome sequence
  printf("Mutated genome sequence at index %d: ", random_index);
  for(int i = 0; i < 100; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");
  
  return 0;
}