//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS];

void print_grid() {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         if (grid[i][j] == 1) {
            printf("O ");
         } else {
            printf("  ");
         }
      }
      printf("\n");
   }
   printf("\n");
}

int count_live_neighbors(int row, int col) {
   int count = 0;
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) {
            continue;
         }
         int r = row + i;
         int c = col + j;
         if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            continue;
         }
         if (grid[r][c] == 1) {
            count++;
         }
      }
   }
   return count;
}

void update_grid() {
   int new_grid[ROWS][COLS];
   
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         int live_neighbors = count_live_neighbors(i, j);
         if (grid[i][j] == 1) {
            if (live_neighbors < 2 || live_neighbors > 3) {
               new_grid[i][j] = 0;
            } else {
               new_grid[i][j] = 1;
            }
         } else {
            if (live_neighbors == 3) {
               new_grid[i][j] = 1;
            } else {
               new_grid[i][j] = 0;
            }
         }
      }
   }

   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         grid[i][j] = new_grid[i][j];
      }
   }
}

void init_grid() {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         grid[i][j] = rand() % 2;
      }
   }
}

int main() {
   srand(time(NULL));
   init_grid();
   while (1) {
      print_grid();
      update_grid();
      usleep(100000);
      system("clear");
   }
   return 0;
}