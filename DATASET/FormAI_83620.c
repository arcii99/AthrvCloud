//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, j;
  
  //seed the random number generator with the current time
  srand(time(NULL));
  
  //generate and print 10 random numbers between 1 and 100
  printf("Here are 10 random numbers between 1 and 100: \n");
  for(i = 0; i < 10; i++) {
    j = rand() % 100 + 1;
    printf("%d ", j);
  }
  
  printf("\n");
  
  //ask the user how many random numbers they want to generate 
  printf("How many random numbers do you want to generate? ");
  scanf("%d", &i);
  
  //generate and print the specified number of random numbers between 1 and 100
  printf("Here are %d random numbers between 1 and 100: \n", i);
  for(j = 0; j < i; j++) {
    printf("%d ", rand() % 100 + 1);
  }
  
  printf("\n");
  
  return 0;
}