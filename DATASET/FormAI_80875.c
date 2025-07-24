//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdbool.h>

#define ROW 7
#define COL 8

int maze[ROW][COL] = {
   {1, 1, 1, 1, 1, 0, 0, 1},
   {0, 0, 1, 0, 1, 1, 1, 1},
   {1, 1, 1, 0, 1, 0, 1, 0},
   {1, 0, 0, 0, 1, 1, 1, 1},
   {1, 1, 1, 0, 1, 0, 0, 1},
   {0, 1, 0, 0, 1, 1, 1, 1},
   {1, 1, 1, 1, 1, 0, 0, 1},
};

int sol[ROW][COL] = {
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
};

void printSolution() {
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
         printf("%d ", sol[i][j]);
      }
      printf("\n");
   }
}

bool isValid(int x, int y) {
   return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solve(int x, int y) {
   if (x == ROW - 1 && y == COL - 1) {
      sol[x][y] = 1;
      return true;
   }

   if (isValid(x, y)) {
      sol[x][y] = 1;

      if (solve(x + 1, y))
         return true;

      if (solve(x, y + 1))
         return true;

      sol[x][y] = 0;
      return false;
   }

   return false;
}

int main() {
   if (solve(0, 0) == false) {
      printf("Solution doesn't exist\n");
      return 0;
   } else {
      printf("Solution Path:\n");
      printSolution();
   }

   return 0;
}