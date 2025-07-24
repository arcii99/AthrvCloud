//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include<stdio.h>

int main()
{
  int n,i,j,k;
  printf("Enter number of rows:\n");
  scanf("%d",&n);
  if(n<1)
  {
    printf("Invalid input\n");
    return 0;
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("*");
    }
    for(k=n-i;k>=1;k--)
    {
      printf("$");
    }
    printf("\n");
  }
  for(i=n-1;i>=1;i--)
  {
    for(j=1;j<=i;j++)
    {
      printf("*");
    }
    for(k=n-i;k>=1;k--)
    {
      printf("$");
    }
    printf("\n");
  }
  return 0;
}