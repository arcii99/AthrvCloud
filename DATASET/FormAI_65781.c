//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, num;
  
  printf("Welcome to the C Random Example Program!\n\n");
  
  // Seed the random number generator with the current time
  srand(time(NULL));
  
  // Generate and print 10 random numbers between 0 and 99
  printf("Here are 10 random numbers between 0 and 99:\n");
  for (i = 0; i < 10; i++) {
    num = rand() % 100;
    printf("%d ", num);
  }
  
  // Generate and print a random lowercase alphabet character
  printf("\n\nHere is a random lowercase alphabet character:\n");
  char letter = (char)(rand() % 26 + 'a');
  printf("%c\n", letter);
  
  // Generate and print a random number between 100 and 1000
  printf("\nHere is a random number between 100 and 1000:\n");
  int rand_num = rand() % 901 + 100;
  printf("%d\n", rand_num);
  
  // Generate and print a random integer from a user-provided range
  printf("\nNow, it's your turn! Enter a lower and upper bound, separated by a space:\n");
  int lower_bound, upper_bound;
  scanf("%d %d", &lower_bound, &upper_bound);
  int rand_int = rand() % (upper_bound - lower_bound + 1) + lower_bound;
  printf("\nAnd your random number is: %d\n", rand_int);
  
  printf("\nThank you for using the C Random Example Program!\n");
  
  return 0;
}