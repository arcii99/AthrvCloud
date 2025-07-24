//FormAI DATASET v1.0 Category: Educational ; Style: brave
/*
 * This program prints a pattern of stars and dashes in a unique way. Buckle up and enjoy the ride!
 */

#include <stdio.h>

int main()
{
  int i, j;

  for(i = 0; i <= 2; i++)
  {
    for(j = 0; j <= 8; j++)
    {
      if(i == 0 && j % 2 == 0)
      {
        printf("*");
      }
      else if((i == 0 && j % 2 != 0) || (i == 1 && j % 2 == 0))
      {
        printf("-");
      }
      else if((i == 1 && j % 2 != 0) || (i == 2 && j % 2 == 0))
      {
        printf("*");
      }
      else
      {
        printf("-");
      }
    }
    printf("\n");
  }

  for(i = 3; i <= 5; i++)
  {
    for(j = 0; j <= 8; j++)
    {
      if(i == 5 && j % 2 == 0)
      {
        printf("*");
      }
      else if((i == 5 && j % 2 != 0) || (i == 4 && j % 2 == 0))
      {
        printf("-");
      }
      else if((i == 4 && j % 2 != 0) || (i == 3 && j % 2 == 0))
      {
        printf("*");
      }
      else
      {
        printf("-");
      }
    }
    printf("\n");
  }

  return 0;
}