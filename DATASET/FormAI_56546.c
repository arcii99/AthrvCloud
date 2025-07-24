//FormAI DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>

int main()
{
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  int i, j, spaces;

  for (i = 1; i <= num; i++)
  {
    // Print spaces
    for (spaces = 1; spaces <= num - i; spaces++)
    {
      printf(" ");
    }

    // Print stars
    for (j = 1; j <= i; j++)
    {
      printf("* ");
    }

    printf("\n");
  }

  return 0;
}