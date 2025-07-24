//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

  char bases[]={'A','C','G','T'};
  int basecount[4];
  
  //initialize base counter to 0
  for(int i=0; i<4; i++){
    basecount[i]=0;
  }
  
  //input genome length
  int genome_length;
  printf("Enter Genome Length: ");
  scanf("%d",&genome_length);
  
  //allocate memory for genome string
  char *genome=(char*)malloc(sizeof(char)*genome_length);
  
  //generate random genome sequence
  srand ( time(NULL) );
  for(int i=0;i<genome_length;i++){
    int r=rand()%4;
    genome[i]=bases[r];
    basecount[r]++;
  }
  
  //print genome sequence
  printf("Genome Sequence: %s\n",genome);
  
  //print base count
  for(int i=0;i<4;i++){
    printf("%c Count: %d\n",bases[i],basecount[i]);
  }
  
  //free memory
  free(genome);
  
  return 0;
}