//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main()
{
   int height, width, half_width, i, j;

   printf("Enter the height of the C: ");
   scanf("%d",&height);

   width = height/2 + 1;
   half_width = width/2;

   for(i=1; i<=height; i++)
   {
       for(j=1; j<=width; j++)
       {
           //print the top horizontal line
           if(i==1 && j<=half_width+1)
           {
               printf("*");
           }
           //print the left vertical line
           else if(j==1 && i!=1 && i!=height)
           {
               printf("*");
           }
           //print the bottom horizontal line
           else if(i==height && j<=half_width+1)
           {
               printf("*");
           }
           //print the right vertical line
           else if(j==half_width+1 && i>1 && i<height)
           {
               printf("*");
           }
           //print the spaces inside the C
           else
           {
               printf(" ");
           }
       }
       //move to the next line
       printf("\n");
   }

   return 0;
}