//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int genomeLength = 100;
  char genome[genomeLength];
  srand(time(0));

  //Initialize genome
  for(int i = 0; i < genomeLength; i++) {
    int randomNum = rand() % 4; //Choose a random number between 0-3
    if(randomNum == 0) {
      genome[i] = 'A';
    } else if(randomNum == 1) {
      genome[i] = 'C';
    } else if(randomNum == 2) {
      genome[i] = 'G';
    } else {
      genome[i] = 'T';
    }
  }

  printf("The generated genome is:\n%s\n", genome);

  //Simulate mutations
  int numMutations = genomeLength / 4; //1/4th of genome length
  for(int i = 0; i < numMutations; i++) {
    int randomIndex = rand() % genomeLength; //Choose a random index
    int randomNum = rand() % 4; //Choose a random number between 0-3
    if(genome[randomIndex] == 'A') {
      if(randomNum == 0) {
        genome[randomIndex] = 'C';
      } else if(randomNum == 1) {
        genome[randomIndex] = 'G';
      } else if(randomNum == 2) {
        genome[randomIndex] = 'T';
      }
    } else if(genome[randomIndex] == 'C') {
      if(randomNum == 0) {
        genome[randomIndex] = 'A';
      } else if(randomNum == 1) {
        genome[randomIndex] = 'G';
      } else if(randomNum == 2) {
        genome[randomIndex] = 'T';
      }
    } else if(genome[randomIndex] == 'G') {
      if(randomNum == 0) {
        genome[randomIndex] = 'A';
      } else if(randomNum == 1) {
        genome[randomIndex] = 'C';
      } else if(randomNum == 2) {
        genome[randomIndex] = 'T';
      }
    } else if(genome[randomIndex] == 'T') {
      if(randomNum == 0) {
        genome[randomIndex] = 'A';
      } else if(randomNum == 1) {
        genome[randomIndex] = 'C';
      } else if(randomNum == 2) {
        genome[randomIndex] = 'G';
      }
    }
  }

  printf("The mutated genome is:\n%s\n", genome);

  return 0;
}