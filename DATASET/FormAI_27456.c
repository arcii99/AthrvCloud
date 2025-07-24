//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>

int main()
{
  // Declare variables
  int surreal_number = 9;
  float imaginary_number = 3.14;
  char surreal_word[] = "banana";
  char imaginary_motion[] = "swimming";
  int i,j;

  // Surrealist simulation
  printf("Welcome to the surreal world of programming!\n");
  printf("Let's start with a surreal number: %d\n", surreal_number);
  printf("Now, let's add an imaginary component to it: %f\n", imaginary_number);
  printf("The result is out of this world: %f %d\n", surreal_number + imaginary_number, surreal_number);

  printf("\n");

  // Surrealistic loop
  for(i=1; i<=surreal_number; i++){
    for(j=1; j<=i; j++){
      printf("%s %d %s\n", surreal_word, j, imaginary_motion);
    }
    printf("\n");
  }

  return 0;
}