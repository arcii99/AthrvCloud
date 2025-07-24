//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 1
#define PATH 0
#define START 2
#define END 3

void generateMaze(int rows, int cols, int* maze);
void displayMaze(int rows, int cols, int* maze);

int main() {
  int rows, cols;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int maze[rows][cols];

  srand(time(NULL));

  generateMaze(rows, cols, &maze[0][0]);

  printf("The generated maze is:\n\n");
  displayMaze(rows, cols, &maze[0][0]);

  return 0;
}

void generateMaze(int rows, int cols, int* maze) {
  // Initialize the maze with walls
  for (int i = 0; i < rows*cols; i++) {
    *(maze+i) = WALL;
  }

  // Randomly choose starting and ending points
  int startRow = rand() % rows;
  int startCol = 0;
  int endRow = rand() % rows;
  int endCol = cols - 1;

  *(maze+startRow*cols+startCol) = START;
  *(maze+endRow*cols+endCol) = END;

  // Generate the maze paths using random walk
  int currentRow = startRow;
  int currentCol = startCol;

  while (currentRow != endRow || currentCol != endCol) {
    if (currentRow > endRow) {
      int direction = rand() % 3;
      currentRow -= (direction == 1) ? 1 : 0;
      currentCol += (direction == 2) ? 1 : 0;
      if (currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
        *(maze+currentRow*cols+currentCol) = PATH;
      }
    } else if (currentRow < endRow) {
      int direction = rand() % 3;
      currentRow += (direction == 1) ? 1 : 0;
      currentCol += (direction == 2) ? 1 : 0;
      if (currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
        *(maze+currentRow*cols+currentCol) = PATH;
      }
    } else {
      int direction = rand() % 2;
      currentCol += (direction == 1) ? 1 : -1;
      if (currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
        *(maze+currentRow*cols+currentCol) = PATH;
      }
    }
  }
}

void displayMaze(int rows, int cols, int* maze) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      switch (*(maze+i*cols+j)) {
        case WALL:
          printf("# ");
          break;
        case PATH:
          printf(". ");
          break;
        case START:
          printf("S ");
          break;
        case END:
          printf("E ");
          break;
      }
    }
    printf("\n");
  }
}