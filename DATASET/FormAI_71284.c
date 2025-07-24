//FormAI DATASET v1.0 Category: Random ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  srand(time(NULL)); // initialize the random seed

  printf("Generating 10 random integers between 0 and 100:\n");
  for(i=0; i<10; i++) {
    printf("%d ", rand() % 101); // generate a random integer between 0 and 100
  }
  printf("\n\n");

  printf("Generating random floats between 0 and 1:\n");
  for(i=0; i<5; i++) {
    printf("%f ", (float)rand()/(float)(RAND_MAX));
  }
  printf("\n\n");

  printf("Generating random doubles between -10 and 10:\n");
  for(i=0; i<3; i++) {
    printf("%f ", (((double)rand()/(double)RAND_MAX)*20.0)-10.0);
  }
  printf("\n\n");

  return 0;
}