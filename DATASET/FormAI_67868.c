//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator with the current time
  srand(time(NULL));
  
  // Generate a random number between 1 and 100
  int random_num = rand() % 100 + 1;
  
  // Print out the random number
  printf("The random number is: %d\n", random_num);
  
  // Perform some operations on the random number
  int square = random_num * random_num;
  int cube = random_num * random_num * random_num;
  int remainder = random_num % 5;
  float square_root = sqrt(random_num);
  
  // Print out the results of the operations
  printf("The square of the random number is: %d\n", square);
  printf("The cube of the random number is: %d\n", cube);
  printf("The remainder of the random number divided by 5 is: %d\n", remainder);
  printf("The square root of the random number is: %f\n", square_root);
  
  return 0;
}