//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 30

void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main() {
   srand((int) time(NULL)); // seed the random number generator
   int maze[ROWS][COLS] = {0}; // initialize all cells to be walls
   generateMaze(maze); // generate the maze
   printMaze(maze); // print the maze
   return 0;
}

void generateMaze(int maze[ROWS][COLS]) {
   // set the starting cell to be empty
   maze[0][0] = 1;
   // initialize variables for the current cell and its neighbors
   int row = 0, col = 0;
   int neighborRow, neighborCol;
   int neighborDirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
   int numNeighbors, randNeighbor;
   // loop until all cells have been visited
   while (1) {
      numNeighbors = 0;
      // find neighbors of the current cell that are walls
      for (int i = 0; i < 4; i++) {
         neighborRow = row + neighborDirs[i][0];
         neighborCol = col + neighborDirs[i][1];
         if (neighborRow >= 0 && neighborRow < ROWS && 
             neighborCol >= 0 && neighborCol < COLS &&
             maze[neighborRow][neighborCol] == 0) {
            numNeighbors++;
         }
      }
      // if the current cell has any unvisited neighbors, select one at random and remove the wall between them
      if (numNeighbors > 0) {
         randNeighbor = rand() % numNeighbors;
         numNeighbors = 0;
         for (int i = 0; i < 4; i++) {
            neighborRow = row + neighborDirs[i][0];
            neighborCol = col + neighborDirs[i][1];
            if (neighborRow >= 0 && neighborRow < ROWS && 
                neighborCol >= 0 && neighborCol < COLS &&
                maze[neighborRow][neighborCol] == 0) {
               if (numNeighbors == randNeighbor) {
                  // remove wall between current cell and selected neighbor
                  if (i == 0) { // neighbor is above
                     maze[row][col] &= ~1;
                     maze[neighborRow][neighborCol] &= ~4;
                  } else if (i == 1) { // neighbor is below
                     maze[row][col] &= ~4;
                     maze[neighborRow][neighborCol] &= ~1;
                  } else if (i == 2) { // neighbor is left
                     maze[row][col] &= ~8;
                     maze[neighborRow][neighborCol] &= ~2;
                  } else if (i == 3) { // neighbor is right
                     maze[row][col] &= ~2;
                     maze[neighborRow][neighborCol] &= ~8;
                  }
                  // move to selected neighbor
                  row = neighborRow;
                  col = neighborCol;
                  maze[row][col] = 1;
                  break;
               } else {
                  numNeighbors++;
               }
            }
         }
      } else {
         // if the current cell has no unvisited neighbors, backtrack to the previous cell
         if (row == 0 && col == 0) {
            // if we have backtracked to the starting cell, the maze is complete
            break;
         } else {
            // move to previous cell
            for (int i = 0; i < 4; i++) {
               neighborRow = row + neighborDirs[i][0];
               neighborCol = col + neighborDirs[i][1];
               if (neighborRow >= 0 && neighborRow < ROWS && 
                   neighborCol >= 0 && neighborCol < COLS &&
                   maze[neighborRow][neighborCol] == 1) {
                  if (i == 0) { // previous cell is above
                     maze[row][col] |= 1;
                     maze[neighborRow][neighborCol] |= 4;
                  } else if (i == 1) { // previous cell is below
                     maze[row][col] |= 4;
                     maze[neighborRow][neighborCol] |= 1;
                  } else if (i == 2) { // previous cell is left
                     maze[row][col] |= 8;
                     maze[neighborRow][neighborCol] |= 2;
                  } else if (i == 3) { // previous cell is right
                     maze[row][col] |= 2;
                     maze[neighborRow][neighborCol] |= 8;
                  }
                  row = neighborRow;
                  col = neighborCol;
                  break;
               }
            }
         }
      }
   }
}

void printMaze(int maze[ROWS][COLS]) {
   // print top border
   for (int i = 0; i < COLS; i++) {
      printf("__");
   }
   printf("\n");
   // print each row of the maze
   for (int i = 0; i < ROWS; i++) {
      // print left border of the row
      printf("|");
      // print each cell in the row
      for (int j = 0; j < COLS; j++) {
         if (maze[i][j] & 1) { // check if cell has top wall
            printf("_");
         } else {
            printf(" ");
         }
         if (maze[i][j] & 8) { // check if cell has left wall
            printf("|");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }
}