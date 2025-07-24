//FormAI DATASET v1.0 Category: Random ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n;
  time_t t;
  
  printf("*** Let's generate some random numbers! ***\n\n");
  
  // Intializes random number generator 
  srand((unsigned) time(&t));

  // Asks the user how many numbers they would like to generate
  printf("How many random numbers would you like to generate? ");
  scanf("%d", &n);
  
  printf("\nHere are %d random numbers generated between 0 and 99: \n\n", n);
  
  // Generates and prints out the random numbers
  for (i = 0; i < n; i++) {
    printf("%d\n", rand() % 100);
  }
  
  printf("\n*** Thanks for using the random number generator! ***");
  
  return 0;
}