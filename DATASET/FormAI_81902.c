//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() 
{
  int i, j, n;
  printf("Enter the number of rows for the C pattern: ");
  scanf("%d", &n);
  
  for(i=1; i<=n; i++) 
  {
    for(j=1; j<=n-i; j++) 
    {
        printf(" ");
    }
    for(j=1; j<=n; j++)
    {
      if(i==1 || i==n || j==1)
      {
          printf("*");
      }
      else
      {
          printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}