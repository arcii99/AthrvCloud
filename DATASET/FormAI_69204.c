//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

void generateMaze(int rows, int cols, char maze[rows][cols]);
void printMaze(int rows, int cols, char maze[rows][cols]);

int main() {
   char maze[ROW][COL];
   generateMaze(ROW, COL, maze);
   printMaze(ROW, COL, maze);
   return 0;
}

void generateMaze(int rows, int cols, char maze[rows][cols]) {
   srand(time(NULL));
   int row, col;
   
   for (row = 0; row < rows; row++) {
      for (col = 0; col < cols; col++) {
          maze[row][col] = '#';
      }
   }

   int current_row = 1;
   int current_col = 1;
   maze[current_row][current_col] = ' ';

   while (current_row != rows-2 || current_col != cols-2) {
      int r = rand() % 4;
      switch (r) {
         case 0: // move up
            if (current_row > 1 && maze[current_row-2][current_col] == '#') { 
               maze[current_row-1][current_col] = ' ';
               maze[current_row-2][current_col] = ' ';
               current_row -= 2;
            }
            break;
         case 1: // move right
            if (current_col < cols-2 && maze[current_row][current_col+2] == '#') {
               maze[current_row][current_col+1] = ' ';
               maze[current_row][current_col+2] = ' ';
               current_col += 2;
            }
            break;
         case 2: // move down
            if (current_row < rows-2 && maze[current_row+2][current_col] == '#') {
               maze[current_row+1][current_col] = ' ';
               maze[current_row+2][current_col] = ' ';
               current_row += 2;
            }
            break;
         case 3: // move left
            if (current_col > 1 && maze[current_row][current_col-2] == '#') {
               maze[current_row][current_col-1] = ' ';
               maze[current_row][current_col-2] = ' ';
               current_col -= 2;
            }
            break;
      }
   }

   maze[1][0] = 'S';
   maze[rows-2][cols-1] = 'E';
}

void printMaze(int rows, int cols, char maze[rows][cols]) {
   int row, col;
   for (row = 0; row < rows; row++) {
      for (col = 0; col < cols; col++) {
         printf("%c", maze[row][col]);
      }
      printf("\n");
   }
}