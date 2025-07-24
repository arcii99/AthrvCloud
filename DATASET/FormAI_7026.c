//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

// Define the structure for the nodes
struct Node {
  int row;
  int col;
  int g_cost;
  int f_cost;
  struct Node *parent;
};

// Function to calculate the heuristic cost
int calcHCost(int end_row, int end_col, int curr_row, int curr_col) {
  int dx = abs(end_col - curr_col);
  int dy = abs(end_row - curr_row);
  return dx + dy;
}

// Function to check if a cell is valid
int checkCell(int x, int y, int map[ROWS][COLS]) {
  if (x < 0 || x >= ROWS || y < 0 || y >= COLS || map[x][y] == 1) {
    return 0;
  }
  return 1;
}

// Function to create a new node
struct Node* createNode(int row, int col, int cost, int f_cost, struct Node* parent) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->row = row;
  newNode->col = col;
  newNode->g_cost = cost;
  newNode->f_cost = f_cost;
  newNode->parent = parent;
  return newNode;
}

// Function to print the path taken
void printPath(struct Node *endNode) {
  if (endNode == NULL) {
    return;
  }
  printPath(endNode->parent);
  printf("(%d,%d)->", endNode->row, endNode->col);
}

// Function for the A* algorithm
void aStar(int start_row, int start_col, int end_row, int end_col, int map[ROWS][COLS]) {
  int closedList[ROWS][COLS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      closedList[i][j] = 0;
    }
  }

  struct Node* startNode = createNode(start_row, start_col, 0, 0, NULL);
  startNode->f_cost = calcHCost(end_row, end_col, start_row, start_col);
  struct Node* currNode = startNode;

  while (1) {
    int minCost = ROWS * COLS;
    int curr_row = currNode->row;
    int curr_col = currNode->col;

    // Check if the current node is the end node
    if (curr_row == end_row && curr_col == end_col) {
      printf("Shortest path from (%d,%d) to (%d,%d):\n", start_row, start_col, end_row, end_col);
      printPath(currNode);
      printf("\n");
      return;
    }

    // Expand the node to get the neighbouring nodes
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        int next_row = curr_row + i;
        int next_col = curr_col + j;
        if (checkCell(next_row, next_col, map)) {
          int g_cost = currNode->g_cost + 1;
          int h_cost = calcHCost(end_row, end_col, next_row, next_col);
          int f_cost = g_cost + h_cost;

          struct Node* nextNode = createNode(next_row, next_col, g_cost, f_cost, currNode);
          if (closedList[next_row][next_col] == 0) {
            closedList[next_row][next_col] = 1;
            if (f_cost < minCost) {
              currNode = nextNode;
              minCost = f_cost;
            }
          }
        }
      }
    }
  }
}

int main() {
  int map[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,1,0,0,1,0},
    {0,1,1,1,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };

  aStar(1, 1, 8, 8, map);

  return 0;
}