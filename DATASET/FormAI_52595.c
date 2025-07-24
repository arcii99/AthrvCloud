//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  // Initializing variables
  char DNA_sequence[50] = {'\0'};
  int i, j;
  srand(time(NULL));
  
  // Generating random DNA sequence
  for(i=0; i<50; i++){
    int num = rand() % 4;
    if(num == 0){
      DNA_sequence[i] = 'A';
    }
    else if(num == 1){
      DNA_sequence[i] = 'T';
    }
    else if(num == 2){
      DNA_sequence[i] = 'C';
    }
    else{
      DNA_sequence[i] = 'G';
    }
  }
  
  // Printing the generated sequence
  printf("Random DNA Sequence: ");
  for(j=0; j<50; j++){
    printf("%c", DNA_sequence[j]);
  }
  printf("\n");
  
  // Counting nucleotides
  int countA = 0, countT = 0, countC = 0, countG = 0;
  for(i=0; i<50; i++){
    switch(DNA_sequence[i]){
      case 'A':
        countA++;
        break;
      case 'T':
        countT++;
        break;
      case 'C':
        countC++;
        break;
      case 'G':
        countG++;
        break;
      default:
        printf("Oh no! Invalid nucleotide found.\n");
        break;
    }
  }
  
  // Printing the nucleotide count
  printf("Nucleotide Count: A=%d T=%d C=%d G=%d\n", countA, countT, countC, countG);
  
  // Determining the complement sequence
  char complement_seq[50] = {'\0'};
  for(i=0; i<50; i++){
    switch(DNA_sequence[i]){
      case 'A':
        complement_seq[i] = 'T';
        break;
      case 'T':
        complement_seq[i] = 'A';
        break;
      case 'C':
        complement_seq[i] = 'G';
        break;
      case 'G':
        complement_seq[i] = 'C';
        break;
      default:
        printf("Oops! Invalid nucleotide found again.\n");
        break;
    }
  }
  
  // Printing the complement sequence
  printf("Complement Sequence: ");
  for(j=0; j<50; j++){
    printf("%c", complement_seq[j]);
  }
  printf("\n");
  
  return 0;
}