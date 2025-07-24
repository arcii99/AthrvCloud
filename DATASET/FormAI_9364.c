//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include<stdio.h>
int main()
{
  int row, column, space, num1, num2, num3, num4, num5;
  
  num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5;
  
  for(row=1;row<=5;row++)
  {
    for(space=1;space<=row;space++)
    {
      printf(" ");
    }
    for(column = 1; column<=(6-row); column++)
    {
      switch(column)
      {
        case 1:
          for(num1;num1<=5;num1++)
          {
            printf("%d",num1);
          }
          break;
        case 2:
          for(num2;num2<=5;num2++)
          {
            printf("%d",num2);
          }
          break;
        case 3:
          for(num3;num3<=5;num3++)
          {
            printf("%d",num3);
          }
          break;
        case 4:
          for(num4;num4<=5;num4++)
          {
            printf("%d",num4);
          }
          break;
        case 5:
          for(num5;num5<=5;num5++)
          {
            printf("%d",num5);
          }
          break;
      }
      printf("   ");
    }
    printf("\n");
  }
  return 0;
}