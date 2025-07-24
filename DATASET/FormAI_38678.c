//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int n=5,i,j,k;
  for(i=1;i<=n;i++)  //for loops for row number of pattern
  {
    for(j=1;j<=n-i;j++)  //for loops for spaces before pattern
    {
      printf(" ");
    }
    for(k=1;k<=(2*i-1);k++)  //for loops for printing pattern
    {
      printf("*");
    }
    printf("\n");
  }
  int m=4;
  for(i=m;i>=1;i--)  //for loops for row number of pattern
  {
    for(j=1;j<=(m-i);j++)  //for loops for spaces before pattern
    {
      printf(" ");
    }
    for(k=1;k<=(2*i-1);k++)  //for loops for printing pattern
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;  //end of code
}