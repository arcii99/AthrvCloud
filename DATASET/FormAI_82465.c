//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41

typedef enum {false, true} bool;

int maze[ROWS][COLS];

void create_maze(int r, int c);
void print_maze();

int main(int argc, char *argv[]) {
   srand(time(0));
   create_maze(1, 1);
   print_maze();
   return 0;
}

void create_maze(int r, int c) {
   int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
   int rand_dir, new_r, new_c;

   maze[r][c] = 1;

   for (int i = 0; i < 4; i++) {
      rand_dir = rand() % 4;
      new_r = r + direction[rand_dir][0];
      new_c = c + direction[rand_dir][1];

      if (new_r >= 0 && new_r < ROWS && new_c >= 0 && new_c < COLS && maze[new_r][new_c] == 0) {
         maze[new_r][new_c] = 1;
         maze[r + (new_r-r)/2][c + (new_c-c)/2] = 1;
         create_maze(new_r, new_c);
      }
   }
}

void print_maze() {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         if (maze[i][j] == 0) {
            printf("# ");
         } else {
            printf("  ");
         }
      }
      printf("\n");
   }
}