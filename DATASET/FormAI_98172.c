//FormAI DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

int main() 
{
  int i, j, k;
  
  // Print the pattern
  for(i=1; i<=5; i++)
  {
    for(j=5; j>i; j--)
    {
      printf(" ");
    }
    for(k=1; k<=(2*i-1); k++)
    {
      printf("*");
    }
    printf("\n");
  }

  for(i=4; i>=1; i--)
  {
    for(j=5; j>i; j--)
    {
      printf(" ");
    }
    for(k=1; k<=(2*i-1); k++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}