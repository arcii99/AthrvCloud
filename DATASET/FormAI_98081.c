//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[ROWS][COLS])
{
  for(int i=0; i<ROWS; i++)
  {
    for(int j=0; j<COLS; j++)
    {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

// Helper function to randomly shuffle the directions
void shuffle(int *array, size_t n)
{
  if (n > 1) 
  {
    size_t i;
    for (i = 0; i < n - 1; i++) 
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

void generateMaze(int maze[ROWS][COLS], int startX, int startY)
{
  // Randomly choose a direction to continue in
  int directions[4] = {0, 1, 2, 3}; // north, east, south, west
  shuffle(directions, 4);
  
  for(int i=0; i<4; i++)
  {
    int currentDirection = directions[i];
    int nextX = startX;
    int nextY = startY;
    
    // Move in the current direction
    if(currentDirection == 0) // north
      nextX--;
    else if(currentDirection == 1) // east
      nextY++;
    else if(currentDirection == 2) // south
      nextX++;
    else if(currentDirection == 3) // west
      nextY--;
    
    // Check if we're out of bounds
    if(nextX < 0 || nextX >= ROWS || nextY < 0 || nextY >= COLS)
      continue;
    
    // Check if the next cell is already part of the maze
    if(maze[nextX][nextY] != -1)
      continue;
    
    // Mark the next cell as part of the maze
    maze[nextX][nextY] = maze[startX][startY];
    
    // Recursively generate a new branch from this cell
    generateMaze(maze, nextX, nextY);
  }
  
}

int main()
{
  srand(time(NULL));
  
  // Initialize the maze with all walls present
  int maze[ROWS][COLS];
  for(int i=0; i<ROWS; i++)
  {
    for(int j=0; j<COLS; j++)
    {
      maze[i][j] = -1; // -1 means unvisited
    }
  }
  
  // Choose a random starting point and mark it as the first "island"
  int startX = rand() % ROWS;
  int startY = rand() % COLS;
  maze[startX][startY] = 0;
  
  // Generate the maze
  generateMaze(maze, startX, startY);
  
  // Print the maze
  printMaze(maze);
  
  return 0;
}