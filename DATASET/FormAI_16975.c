//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>

int main()
{
  int n;
  
  printf("Enter the number of rows you want to print: ");
  scanf("%d", &n);
  
  int rows = n, columns = n, sum = rows + columns - 1;
  
  for(int i=1; i<=rows; ++i)
  {
    for(int j=1; j<=columns; ++j)
    {
      if(j==1 || j==columns || (i+j)==sum+1)
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  
  return 0;
}