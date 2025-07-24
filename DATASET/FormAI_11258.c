//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
int main()
{
  int i, j, k;
  printf("\n\n\t  Let's print a colorful C pattern!\n\n");

  for (i = 1; i <= 6; i++)
  {
    for (j = 1; j <= 6; j++)
    {
      k = i + j;
      if (k % 2 == 0)
      {
        printf("  C ");
      }
      else
      {
        printf("  O ");
      }
    }
    printf("\n");
  }
  printf("\n\n\t  Done printing the C pattern!\n\n");
  return 0;
}