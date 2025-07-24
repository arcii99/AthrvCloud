//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

   srand(time(NULL));

   int maze[20][20]; // maze representation
   int visited[20][20]; // keeps track of visited positions
   int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // possible move directions
   int currentRow = 1, currentCol = 1; // current position in the maze
   int endRow = 18, endCol = 18; // end position in the maze
   int pathLength = 0; // length of path taken
   bool solved = false; // flag to check if maze is solved

   // initialize maze and visited arrays randomly
   for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 20; j++) {
         if(i == 0 || i == 19 || j == 0 || j == 19 || rand() % 3 == 0) {
            maze[i][j] = 1;
         } else {
            maze[i][j] = 0;
         }
         visited[i][j] = 0;
      }
   }

   // mark start and end positions
   maze[1][1] = 2;
   maze[18][18] = 3;

   printf("Maze Representation:\n");
   for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 20; j++) {
         printf("%d ", maze[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   // find path using depth first search
   while(!solved) {

      visited[currentRow][currentCol] = 1;

      if(currentRow == endRow && currentCol == endCol) {
         solved = true;
         maze[currentRow][currentCol] = 4;
         break;
      }

      bool moved = false;
      for(int i = 0; i < 4; i++) {
         int newRow = currentRow + moves[i][0];
         int newCol = currentCol + moves[i][1];

         if(maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
            currentRow = newRow;
            currentCol = newCol;
            maze[newRow][newCol] = 2;
            pathLength++;
            moved = true;
            break;
         }
      }

      if(!moved) {

         if(pathLength == 0) {
            printf("Maze is unsolvable.\n");
            return 0;
         }

         pathLength--;
         maze[currentRow][currentCol] = 0;

         for(int i = 3; i >= 0; i--) {
            int newRow = currentRow + moves[i][0];
            int newCol = currentCol + moves[i][1];

            if(maze[newRow][newCol] == 2) {
               currentRow = newRow;
               currentCol = newCol;
               break;
            }
         }
      }

   }

   printf("Solution:\n");
   for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 20; j++) {
         printf("%d ", maze[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   return 0;

}