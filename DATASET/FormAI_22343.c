//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  srand(time(NULL)); // set seed for random number generation
  
  printf("Generating and printing 10 random numbers between 1 and 100:\n");
  for(i=0; i<10; i++) {
    printf("%d\n", rand()%100 + 1);
  }
  
  return 0;
}