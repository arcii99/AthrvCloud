//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main()
{
   printf("Welcome to my unique C Graph representation program!\n");
   printf("In this program, we will be drawing a funny looking graph. Are you ready? Let's go!\n\n");

   printf("First, we need to declare some variables to help us draw the graph.\n");
   printf("Let's declare an integer variable x, which will represent our x-axis.\n");
   printf("And let's declare an integer variable y, which will represent our y-axis.\n\n");
   int x, y;

   printf("Now let's initialize our variables.\n");
   printf("We'll start x at -10, and y at 0.\n\n");
   x = -10;
   y = 0;

   printf("Great! Now let's start drawing our graph.\n");
   printf("We'll use a for loop to go through each point on the graph.\n\n");

   for(y = 10; y >= -10; y--)
   {
      for(x = -10; x <= 10; x++)
      {
         if(x == 0 || y == 0)
         {
            printf("* ");
         }
         else if(x % y == 0)
         {
            printf("+ ");
         }
         else if(x % 2 == 0)
         {
            printf("O ");
         }
         else
         {
            printf(". ");
         }
      }
      printf("\n");
   }

   printf("\nThere you have it! A funny looking graph.\n");
   printf("I hope you had as much fun drawing it as I did!\n");

   return 0;
}