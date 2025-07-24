//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

/* Define global variables */
#define ROWS 5
#define COLS 5

/* Define pathfinding function using Depth First Search algorithm */
void DFS(char **map, int row, int col, int visited[ROWS][COLS]) {
  int rowMoves[4] = {-1, 0, 0, 1};  // Define move directions for rows
  int colMoves[4] = {0, -1, 1, 0};  // Define move directions for columns
  visited[row][col] = 1;  // Mark current cell as visited

  // Check if the current cell is the destination
  if (map[row][col] == 'D') {
    printf("Destination has been reached!\n");
    return;
  }

  // Loop over all possible moves
  for (int i = 0; i < 4; i++) {
    int nextRow = row + rowMoves[i];
    int nextCol = col + colMoves[i];

    /* Check if the next move is within the map limits, if it's not a wall(#),and it has not been visited yet*/
    if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && map[nextRow][nextCol] != '#' && visited[nextRow][nextCol] == 0) {
      DFS(map, nextRow, nextCol, visited);  // Next move found! Keep going!
    }
  }
}

int main() {
  char *map[] = {"S....", ".##..", "##...", "...##", "..D.."};  // Define the map
  int visited[ROWS][COLS] = {0};  // Initialize visited cells array with 0's
  int startX, startY;

  // Find the starting position "S"
  for (int i=0; i<ROWS; i++) {
    for (int j=0; j<COLS; j++) {
      if (map[i][j] == 'S') {
        startX = i;
        startY = j;
        break;
      }
    }
  }

  /* Call DFS algorithm*/
  DFS(map, startX, startY, visited);

  return 0;
}