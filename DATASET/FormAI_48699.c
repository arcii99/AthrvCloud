//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void createMaze(char maze[][COL]);
void printMaze(char maze[][COL]);
void generateMaze(char maze[][COL], int row, int col, int x, int y);

int main()
{
  char maze[ROW][COL];
  srand(time(NULL)); // Set random seed

  createMaze(maze); // Create initial maze
  printf("Initial maze:\n");
  printMaze(maze); // Print initial maze
  
  // Set start and end points
  int startX = rand() % ROW;
  int startY = rand() % COL;
  int endX, endY;
  do
  {
    endX = rand() % ROW;
    endY = rand() % COL;
  } while (startX == endX && startY == endY); // Make sure start and end points are not the same

  printf("\nStart point: (%d,%d)\nEnd point: (%d,%d)\n\n", startX, startY, endX, endY);

  // Generate maze path from start to end
  generateMaze(maze, ROW, COL, startX, startY);
  if (maze[endX][endY] != 'E')
  {
    maze[endX][endY] = 'E'; // Set end point
  }

  printf("Generated maze:\n");
  printMaze(maze); // Print generated maze

  return 0;
}

// Create initial randomized maze
void createMaze(char maze[][COL])
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      maze[i][j] = rand() % 2 == 0 ? '#' : '.'; // 50/50 chance of wall or path
    }
  }
}

// Print maze
void printMaze(char maze[][COL])
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// Generate maze path from start to end
void generateMaze(char maze[][COL], int row, int col, int x, int y)
{
  maze[x][y] = 'S'; // Set start point

  int dx[4] = {1,-1,0,0}; // Adjacent cells in x direction
  int dy[4] = {0,0,1,-1}; // Adjacent cells in y direction

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i]; // Next cell in x direction
    int ny = y + dy[i]; // Next cell in y direction
    if (nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] == '.')
    {
      // Remove wall between current cell and next cell
      int rx = (x + nx) / 2; // Cell in between current and next cell in x direction
      int ry = (y + ny) / 2; // Cell in between current and next cell in y direction
      maze[rx][ry] = '.';
      generateMaze(maze, row, col, nx, ny); // Recurse with next cell as current cell
    }
  }
}