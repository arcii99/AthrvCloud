//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // Seed for random number generator
  int a = rand() % 10 + 1; // Random number between 1 and 10
  int b = rand() % 10 + 1; // Random number between 1 and 10

  printf("What is %d + %d?\n", a, b);

  int answer;
  scanf("%d", &answer);

  while (answer != a + b)
  {
    printf("Incorrect. Try again.\n");
    scanf("%d", &answer);
  }

  printf("Correct! Now solve this equation:\n");

  int c = rand() % 10 + 1; // Random number between 1 and 10
  int d = rand() % 10 + 1; // Random number between 1 and 10
  int e = rand() % 10 + 1; // Random number between 1 and 10

  printf("%d + %d * %d = ?\n", c, d, e);

  int answer2;
  scanf("%d", &answer2);

  while (answer2 != c + d * e)
  {
    printf("Incorrect. Try again.\n");
    scanf("%d", &answer2);
  }

  printf("Well done!\n");

  return 0;
}