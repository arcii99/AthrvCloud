//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>
int main()
{
   int height, width;
   printf("Enter the height of the pattern: ");
   scanf("%d", &height);
   printf("Enter the width of the pattern: ");
   scanf("%d", &width);

   int i, j;
   for(i=0;i<height;i++)
   {
      for(j=0;j<width;j++)
      {
         if (i==0 || i==height-1 || i==j || j==width-1-i || j==0 || j==width-1)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }

   return 0;
}