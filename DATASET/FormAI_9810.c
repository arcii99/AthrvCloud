//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL)); // Seed the random number generator
   
   char maze[10][10]; // Our maze
   int x = rand() % 10; // Random starting point
   int y = rand() % 10;
   
   // Let's fill the maze with walls and spaces
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         if(rand() % 3 == 0)
         {
            maze[i][j] = 'X'; // Wall
         }
         else
         {
            maze[i][j] = ' '; // Space
         }
      }
   }
   
   maze[x][y] = 'S'; // Starting point
   maze[9][9] = 'E'; // End point
   
   // Let's print the maze
   printf("Maze:\n");
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         printf("%c", maze[i][j]);
      }
      printf("\n");
   }
   
   // Let's find the shortest path to the end using the Right-Hand Rule
   printf("\nFinding shortest path...\n");
   int direction = 0; // 0=right, 1=down, 2=left, 3=up
   while(x != 9 || y != 9) // Loop until we reach the end
   {
      // Let's determine the new direction
      int new_direction = (direction + 3) % 4;
      while(maze[x+new_direction/2][y+(new_direction+1)/2] == 'X')
      {
         new_direction = (new_direction + 1) % 4;
      }
      
      // Let's move in the new direction
      switch(new_direction)
      {
         case 0:
            maze[x][++y] = '+';
            break;
         case 1:
            maze[++x][y] = '+';
            break;
         case 2:
            maze[x][--y] = '+';
            break;
         case 3:
            maze[--x][y] = '+';
            break;
      }
      
      direction = new_direction; // Update the direction
   }
   
   // Let's print the shortest path
   printf("\nShortest path:\n");
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         if(maze[i][j] == '+')
         {
            printf("*");
         }
         else
         {
            printf("%c", maze[i][j]);
         }
      }
      printf("\n");
   }
   
   return 0; // Done!
}