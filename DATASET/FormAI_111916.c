//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>
int main()
{
  int i, j;
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5;j++)
    {
      if(i==1 || i==5 || j==1)
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  printf("\n\n");
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5;j++)
    {
      if(i==1 || i==3 || i==5 || j==1)
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  printf("\n\n");
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5;j++)
    {
      if(i==j || i==(6-j))
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  printf("\n\n");
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5;j++)
    {
      if(i==1 || i==5 || j==1 || j==5)
        printf("0 ");
      else
      {
        if(i==3 && j==3)
          printf("* ");
        else
          printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n\n");
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5;j++)
    {
      if(i==j || j==(6-i))
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  return 0;
}