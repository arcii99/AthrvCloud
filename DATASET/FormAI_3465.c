//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main()
{
   int r, c, i, j, count=0, start_row, start_col, end_row, end_col, dir;
   char maze[ROWS][COLS];
   
   srand(time(NULL));   //Seed the random number generator

   //Initialize maze with walls on all sides
   for(r=0; r<ROWS; r++)
      for(c=0; c<COLS; c++)
         maze[r][c] = '#';

   // Choose random start and end points
   start_row = rand() % ROWS;
   start_col = 0;
   end_row = rand() % ROWS;
   end_col = COLS-1;
   maze[start_row][start_col] = 'S';   //Set Start point
   maze[end_row][end_col] = 'E';       //Set End point

   //Carve out maze
   i = start_row;
   j = start_col;
   while(i != end_row || j != end_col)
   {
      //Choose random direction to move
      dir = rand() % 4;

      //Move North
      if(dir == 0 && i > 0 && maze[i-1][j] == '#')
      {
         maze[i-1][j] = ' ';
         i--;
      }
      //Move East
      else if(dir == 1 && j < COLS-1 && maze[i][j+1] == '#')
      {
         maze[i][j+1] = ' ';
         j++;
      }
      //Move South
      else if(dir == 2 && i < ROWS-1 && maze[i+1][j] == '#')
      {
         maze[i+1][j] = ' ';
         i++;
      }
      //Move West
      else if(dir == 3 && j > 0 && maze[i][j-1] == '#')
      {
         maze[i][j-1] = ' ';
         j--;
      }

      //If trapped, backtrack until path is found
      if(maze[i-1][j] != '#' && maze[i][j+1] != '#' && maze[i+1][j] != '#' && maze[i][j-1] != '#')
      {
         while(maze[i-1][j] != '#' || maze[i][j+1] != '#' || maze[i+1][j] != '#' || maze[i][j-1] != '#')
         {
            if(maze[i-1][j] != '#' && dir != 2)
            {
               maze[i][j] = ' ';
               i--;
               dir = 0;
            }
            else if(maze[i][j+1] != '#' && dir != 3)
            {
               maze[i][j] = ' ';
               j++;
               dir = 1;
            }
            else if(maze[i+1][j] != '#' && dir != 0)
            {
               maze[i][j] = ' ';
               i++;
               dir = 2;
            }
            else if(maze[i][j-1] != '#' && dir != 1)
            {
               maze[i][j] = ' ';
               j--;
               dir = 3;
            }
         }
      }
   }

   //Print maze
   for(r=0; r<ROWS; r++)
   {
      for(c=0; c<COLS; c++)
         printf("%c", maze[r][c]);
      printf("\n");
   }

   return 0;
}