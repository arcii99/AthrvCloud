//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // seed random number generator
  
  int a = rand() % 10; // generate random number between 0 and 9
  int b = rand() % 10;
  
  printf("What is %d + %d?\n", a, b);
  
  int answer;
  scanf("%d", &answer); // get user input
  
  if (answer == (a + b)) {
    printf("Correct! Good job.\n");
  } else {
    printf("Incorrect. The answer is %d.\n", a + b);
  }

  return 0;
}