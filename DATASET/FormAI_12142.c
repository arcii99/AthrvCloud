//FormAI DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>

int main()
{
  int n, i, j;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Print upper half of the pattern
  for (i = 0; i < n; i++)
  {
    for (j = 0; j <= i; j++)
    {
      printf("%c ", j+65);
    }
    printf("\n");
  }

  // Print lower half of the pattern
  for (i = n-1; i >= 0; i--)
  {
    for (j = 0; j <= i; j++)
    {
      printf("%c ", j+65);
    }
    printf("\n");
  }

  return 0;
}