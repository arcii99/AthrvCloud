//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator using the current time
  srand(time(NULL));

  // Generate 10 random numbers between 0 and 99
  printf("Generating 10 random numbers between 0 and 99...\n");
  int i;
  for (i = 0; i < 10; i++) {
    int random_num = rand() % 100;
    printf("%d ", random_num);
  }
  printf("\n\n");

  // Generate 10 random letters
  printf("Generating 10 random letters...\n");
  for (i = 0; i < 10; i++) {
    char random_letter = 'a' + rand() % 26;
    printf("%c ", random_letter);
  }
  printf("\n\n");

  // Generate 10 random boolean values
  printf("Generating 10 random boolean values...\n");
  for (i = 0; i < 10; i++) {
    // Generate a random number between 0 and 1
    int random_bool_num = rand() % 2;

    // Convert the random number to a boolean value
    // 0 = false, 1 = true
    _Bool random_bool = (_Bool) random_bool_num;
    printf("%d ", random_bool);
  }
  printf("\n\n");

  // Generate a random 5x5 matrix of integers between 0 and 9
  printf("Generating a random 5x5 matrix of integers between 0 and 9...\n");
  int j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      int random_num = rand() % 10;
      printf("%d ", random_num);
    }
    printf("\n");
  }

  // Exit the program
  return 0;
}